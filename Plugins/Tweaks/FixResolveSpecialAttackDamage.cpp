#include "nwnx.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSCombatAttackData.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static bool s_InResolveSpecialAttack;

inline bool GetAttackResultHit(CNWSCombatAttackData *pAttackData)
{
    if (pAttackData->m_nAttackResult == 1 || pAttackData->m_nAttackResult == 3 || pAttackData->m_nAttackResult == 5 ||
        pAttackData->m_nAttackResult == 6 || pAttackData->m_nAttackResult == 7 || pAttackData->m_nAttackResult == 10)
        return true;
    else
        return false;
}

void FixResolveSpecialAttackDamage() __attribute__((constructor));
void FixResolveSpecialAttackDamage()
{
    if (!Config::Get<bool>("FIX_RESOLVE_SPECIAL_ATTACK_DAMAGE", false))
        return;

    LOG_INFO("Special Attacks will not resolve damage on a miss.");

    static Hooks::Hook s_ResolveMeleeSpecialAttackHook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature25ResolveMeleeSpecialAttackEiiP10CNWSObjecti,
        (void*)+[](CNWSCreature *pThis, int32_t nAttackIndex, int32_t nAttacks, CNWSObject *pTarget, int32_t nTimeAnimation) -> void
        {
            s_InResolveSpecialAttack = true;
            s_ResolveMeleeSpecialAttackHook->CallOriginal<void>(pThis, nAttackIndex, nAttacks, pTarget, nTimeAnimation);
            s_InResolveSpecialAttack = false;

        }, Hooks::Order::Earliest);

    static Hooks::Hook s_ResolveRangedSpecialAttackHook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature26ResolveRangedSpecialAttackEP10CNWSObjecti,
        (void*)+[](CNWSCreature *pThis, CNWSObject *pTarget, int32_t nTimeAnimation) -> void
        {
            s_InResolveSpecialAttack = true;
            s_ResolveRangedSpecialAttackHook->CallOriginal<void>(pThis, pTarget, nTimeAnimation);
            s_InResolveSpecialAttack = false;

        }, Hooks::Order::Earliest);

    static Hooks::Hook s_ResolveDamageHook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature13ResolveDamageEP10CNWSObject,
        (void*)+[](CNWSCreature *pThis, CNWSObject *pTarget) -> void
        {
            if (s_InResolveSpecialAttack)
            {
                if (!GetAttackResultHit(pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack)))
                    return;
            }

            s_ResolveDamageHook->CallOriginal<void>(pThis, pTarget);
        }, Hooks::Order::Early);

    static Hooks::Hook s_ResolvePostMeleeDamageHook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature22ResolvePostMeleeDamageEP10CNWSObject,
        (void*)+[](CNWSCreature *pThis, CNWSObject *pTarget) -> void
        {
            if (s_InResolveSpecialAttack)
            {
                if (!GetAttackResultHit(pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack)))
                    return;
            }

            s_ResolvePostMeleeDamageHook->CallOriginal<void>(pThis, pTarget);
        }, Hooks::Order::Early);

    static Hooks::Hook s_ResolvePostRangedDamageHook =
        Hooks::HookFunction(Functions::_ZN12CNWSCreature23ResolvePostRangedDamageEP10CNWSObject,
        (void*)+[](CNWSCreature *pThis, CNWSObject *pTarget) -> void
        {
            if (s_InResolveSpecialAttack)
            {
                if (!GetAttackResultHit(pThis->m_pcCombatRound->GetAttack(pThis->m_pcCombatRound->m_nCurrentAttack)))
                {
                    pThis->ResolveRangedMiss(pTarget);
                    return;
                }
            }

            s_ResolvePostRangedDamageHook->CallOriginal<void>(pThis, pTarget);
        }, Hooks::Order::Early);
}

}
