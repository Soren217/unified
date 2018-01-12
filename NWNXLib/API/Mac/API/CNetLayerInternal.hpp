#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedCExoString.hpp"
#include "CExoString.hpp"
#include "CNetLayerPlayerInfo.hpp"
#include "CNetLayerWindow.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CBaseExoApp;
struct CExoArrayListTemplatedCExoString;
struct CExoNet;
struct CExoNetExtendableBuffer;
struct CNetLayerSessionInfo;

struct CNetLayerInternal
{
    CBaseExoApp* m_pcExoApp;
    CExoNet* m_pcExoNet;
    int32_t m_bInitialized;
    CNetLayerWindow m_aWindows[96];
    CNetLayerPlayerInfo m_pcPlayerInfo[96];
    CExoNetExtendableBuffer* m_pebFrameStorage;
    uint8_t m_pCompressBuffer[131072];
    uint8_t m_pUncompressBuffer[131072];
    uint32_t m_nCRC32[256];
    uint8_t m_pPacketizeBuffer[960];
    int32_t m_bServerMode;
    CExoString m_sSessionName;
    CExoString m_sPlayerPassword;
    CExoString m_sGameMasterPassword;
    CExoString m_sServerAdminPassword;
    uint32_t m_nSessionMaxPlayers;
    int32_t m_bEnumerateSessions;
    int32_t m_bEnumerateSpecific;
    int32_t m_bEnumerateLocal;
    uint32_t m_nLastEnumerateSessions;
    uint32_t m_nLastEnumerateSessionsList;
    uint32_t m_nLastPurgeConnections;
    int32_t m_bEnumerateSessionsPerFrame;
    CNetLayerSessionInfo* m_pcSessionInfo;
    uint32_t m_nMaxSessionCnt[4];
    uint32_t m_nSessionInfoSize;
    uint32_t m_nSessionInfoSectionSize;
    int32_t m_bSessionInfoChanged[4];
    int32_t m_bConnected;
    int32_t m_bConnectToSession;
    CExoString m_sConnectPassword;
    uint32_t m_nConnectType;
    int32_t m_bConnectReplyReceived;
    int32_t m_bConnectReplyValue;
    uint32_t m_nConnectReplyErrorCode;
    uint32_t m_nConnectSendConnectionId;
    uint32_t m_nConnectReplyConnectionId;
    uint32_t m_nConnectTimeout;
    int32_t m_bTranslateInetAddress;
    int32_t m_bTranslateReplyReceived;
    int32_t m_bTranslateReplyValue;
    uint32_t m_nTranslateTimeout;
    uint32_t m_nServerWindow;
    uint32_t m_nClientPermittedPlayer;
    uint32_t m_nClientPermittedGameMaster;
    uint32_t m_nClientPermittedServerAdmin;
    CExoLinkedListTemplatedCExoString m_lBadPasswordAttempts;
    uint32_t m_nDisconnectStrref;
    uint32_t m_nFavListSize;
    CExoString* m_asFavList;
    uint32_t m_nFavListEnumerated;
    uint32_t m_nFavListFramesToNextEnumeration;
    uint32_t m_nHistListSize;
    CExoString* m_asHistList;
    uint32_t m_nHistListEnumerated;
    uint32_t m_nHistListFramesToNextEnumeration;
    uint32_t m_nBuddyListSize;
    CExoString* m_asBuddyList;
    uint32_t m_nBuddyListEnumerated;
    uint32_t m_nBuddyListFramesToNextEnumeration;
    uint32_t m_nMaxSlidingWindow;
    CExoString m_sMstServerPassword;
    uint16_t m_nExpansionPackReqd;
    uint32_t m_nSinglePlayerSlidingWindow;
    int32_t m_nLanguage;
    int32_t m_bAnyWindowHasQueuedMessages;
    int32_t m_bDisallowLoginWhileMasterServerIsNotResponding;
    int32_t m_bValidateLoginWhileMasterServerIsNotResponding;

    // The below are auto generated stubs.
    CNetLayerInternal(const CNetLayerInternal&) = default;
    CNetLayerInternal& operator=(const CNetLayerInternal&) = default;

    CNetLayerInternal();
    ~CNetLayerInternal();
    int32_t BroadcastMessageToAddress(uint32_t, uint32_t, unsigned char*, uint32_t);
    void CheckMasterServerTimeouts();
    void CleanUpEnumerateSpecific();
    void ClearSessionInfoChanged(uint32_t);
    int32_t CloseStandardConnection(int32_t);
    int32_t ConnectionIdToSlidingWindow(uint32_t, uint32_t*);
    uint32_t ConnectToSessionLoop();
    uint32_t CRCBlock(unsigned char*, uint32_t);
    void CRCBuildTable();
    void CRCEncodeFrame(unsigned char*, uint32_t);
    int32_t CRCVerifyFrame(unsigned char*, uint32_t);
    int32_t DisconnectFromSession();
    int32_t DisconnectPlayer(uint32_t, uint32_t, int32_t, int32_t);
    int32_t DropConnectionToServer();
    int32_t EndConnectToSession();
    int32_t EndEnumerateSessions();
    int32_t EndEnumerateSessionsSection(uint32_t);
    int32_t EndInternetAddressTranslation();
    int32_t EndPing(uint32_t);
    int32_t EndProtocol(uint32_t);
    int32_t EndServerMode();
    uint32_t EnumerateSessionsList(unsigned char);
    int32_t EnumerateSessionsLoop();
    int32_t FindPlayerName(CExoString, uint32_t);
    uint32_t GetConnectionError();
    CBaseExoApp* GetExoApp();
    CExoString GetGameMasterPassword();
    uint32_t GetInternetAddressTranslationStatus(unsigned char*);
    int32_t GetIPBySessionId(uint32_t, CExoString*);
    CExoString GetLocalAdapterString(uint32_t, uint32_t);
    uint32_t GetLocalPrivileges(uint32_t);
    int32_t GetMessageFromStandardConnection(int32_t*, char**, int32_t*);
    int32_t GetNumberLocalAdapters(uint32_t);
    int32_t GetPasswordRequired();
    CExoString GetPlayerAddress(uint32_t);
    int32_t GetPlayerAddressData(uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
    CExoString GetPlayerPassword();
    uint32_t GetPortBySessionId(uint32_t);
    uint32_t GetSendUDPSocket();
    CExoString GetServerAdminPassword();
    int32_t GetServerConnected();
    CExoString GetServerNetworkAddress();
    uint32_t GetServerPlayerCount();
    CNetLayerSessionInfo* GetSessionInfo(uint32_t);
    uint32_t GetSessionMaxPlayers();
    CExoString GetSessionName();
    uint32_t GetUDPRecievePort();
    int32_t GetWindowSendIdByReceiveId(uint32_t, uint32_t*);
    int32_t HandleBNCRMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNCSMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNDMMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNDPMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNDRMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNDSMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNERMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNESMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNLMMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNLRMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNVRMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNVSMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNXIMessage(uint32_t, unsigned char*, uint32_t);
    int32_t HandleBNXRMessage(uint32_t, unsigned char*, uint32_t);
    int32_t Initialize(CBaseExoApp*);
    int32_t IsConnectedToLocalhost();
    int32_t IsPlayerIpSameAsConnection(uint32_t, uint32_t);
    int32_t MessageArrived(uint32_t, uint32_t, uint32_t, int32_t);
    int32_t NonWindowMessages(uint32_t, unsigned char*, uint32_t);
    int32_t OpenStandardConnection(int32_t, CExoString, int32_t);
    int32_t PacketizeSendMessageToPlayer(uint32_t, unsigned char*, uint32_t, uint32_t);
    int32_t PacketizeSmallMessageToPlayer(uint32_t, unsigned char*, uint32_t, uint32_t);
    int32_t PlacePacketInSendQueues(uint32_t, int32_t, unsigned char*, uint32_t, int32_t);
    int32_t PlayerIdToConnectionId(uint32_t, uint32_t*);
    int32_t PlayerIdToSlidingWindow(uint32_t, uint32_t*);
    void ProcessReceivedFrames(int32_t);
    int32_t PurgeConnections();
    int32_t RequestExtendedServerInfo(uint32_t, int32_t, int32_t);
    void ResetEnumerateSessionsList(unsigned char);
    int32_t SendBNCRMessage(uint32_t, unsigned char, uint32_t);
    int32_t SendBNCSMessage(uint32_t, unsigned char, int32_t, int32_t, const CExoString&, const CExoString&, const CExoString&, uint32_t&);
    void SendBNDMMessage();
    void SendBNDPMessage(uint32_t, uint32_t);
    int32_t SendBNDSMessage(uint32_t);
    int32_t SendBNESDirectMessageToAddress(CExoString, unsigned char);
    int32_t SendBNLMMessage(uint32_t, uint32_t);
    int32_t SendBNVRMessage(uint32_t, unsigned char);
    int32_t SendBNVSMessage(const CExoArrayListTemplatedCExoString*, const CExoString&, const CExoString&);
    int32_t SendDirectMessage(uint32_t, unsigned char*, uint32_t, uint32_t, uint32_t);
    int32_t SendMessageToAddress(uint32_t, unsigned char*, uint32_t);
    int32_t SendMessageToPlayer(uint32_t, unsigned char*, uint32_t, uint32_t);
    int32_t SendMessageToStandardConnection(int32_t, char*, int32_t);
    int32_t SetGameMasterPassword(CExoString);
    void SetMasterServerInternetAddress(const unsigned char*, uint32_t);
    uint32_t SetNetworkAddressData(uint32_t, unsigned char*, unsigned char*, uint32_t);
    void SetPlayerConnected(uint32_t);
    int32_t SetPlayerPassword(CExoString);
    int32_t SetServerAdminPassword(CExoString);
    void SetServerLanguage(int32_t);
    void SetSessionMaxPlayers(uint32_t);
    void SetSessionName(CExoString);
    int32_t SetSlidingWindow(uint32_t, uint32_t, uint32_t*);
    void SetUpPlayBackConnection();
    int32_t ShutDown();
    void ShutDownClientInterfaceWithReason(uint32_t);
    int32_t StartConnectToSession(uint32_t, const CExoString&, int32_t, int32_t, const CExoString&, uint32_t, uint32_t, const CExoString&, const CExoString&);
    int32_t StartEnumerateSessions(uint32_t, int32_t, unsigned char*, uint16_t, int32_t, uint32_t);
    int32_t StartEnumerateSessionsSection(uint32_t, uint32_t, CExoString*);
    int32_t StartInternetAddressTranslation(CExoString, uint32_t, uint32_t);
    int32_t StartPing(uint32_t);
    int32_t StartProtocol(uint32_t, uint32_t, uint32_t, uint32_t);
    int32_t StartServerMode(CExoString, uint32_t);
    void StoreMessage(unsigned char*, uint32_t);
    int32_t UncompressMessage(uint32_t, unsigned char*, uint32_t);
    int32_t UpdateStatusLoop(uint32_t);
    int32_t ValidatePlayerAgainstLastSuccessfulLogin(CExoString, CExoString);
};

void CNetLayerInternal__CNetLayerInternalCtor__0(CNetLayerInternal* thisPtr);
void CNetLayerInternal__CNetLayerInternalDtor__0(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__BroadcastMessageToAddress(CNetLayerInternal* thisPtr, uint32_t, uint32_t, unsigned char*, uint32_t);
void CNetLayerInternal__CheckMasterServerTimeouts(CNetLayerInternal* thisPtr);
void CNetLayerInternal__CleanUpEnumerateSpecific(CNetLayerInternal* thisPtr);
void CNetLayerInternal__ClearSessionInfoChanged(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__CloseStandardConnection(CNetLayerInternal* thisPtr, int32_t);
int32_t CNetLayerInternal__ConnectionIdToSlidingWindow(CNetLayerInternal* thisPtr, uint32_t, uint32_t*);
uint32_t CNetLayerInternal__ConnectToSessionLoop(CNetLayerInternal* thisPtr);
uint32_t CNetLayerInternal__CRCBlock(CNetLayerInternal* thisPtr, unsigned char*, uint32_t);
void CNetLayerInternal__CRCBuildTable(CNetLayerInternal* thisPtr);
void CNetLayerInternal__CRCEncodeFrame(CNetLayerInternal* thisPtr, unsigned char*, uint32_t);
int32_t CNetLayerInternal__CRCVerifyFrame(CNetLayerInternal* thisPtr, unsigned char*, uint32_t);
int32_t CNetLayerInternal__DisconnectFromSession(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__DisconnectPlayer(CNetLayerInternal* thisPtr, uint32_t, uint32_t, int32_t, int32_t);
int32_t CNetLayerInternal__DropConnectionToServer(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__EndConnectToSession(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__EndEnumerateSessions(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__EndEnumerateSessionsSection(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__EndInternetAddressTranslation(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__EndPing(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__EndProtocol(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__EndServerMode(CNetLayerInternal* thisPtr);
uint32_t CNetLayerInternal__EnumerateSessionsList(CNetLayerInternal* thisPtr, unsigned char);
int32_t CNetLayerInternal__EnumerateSessionsLoop(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__FindPlayerName(CNetLayerInternal* thisPtr, CExoString, uint32_t);
uint32_t CNetLayerInternal__GetConnectionError(CNetLayerInternal* thisPtr);
CBaseExoApp* CNetLayerInternal__GetExoApp(CNetLayerInternal* thisPtr);
CExoString CNetLayerInternal__GetGameMasterPassword(CNetLayerInternal* thisPtr);
uint32_t CNetLayerInternal__GetInternetAddressTranslationStatus(CNetLayerInternal* thisPtr, unsigned char*);
int32_t CNetLayerInternal__GetIPBySessionId(CNetLayerInternal* thisPtr, uint32_t, CExoString*);
CExoString CNetLayerInternal__GetLocalAdapterString(CNetLayerInternal* thisPtr, uint32_t, uint32_t);
uint32_t CNetLayerInternal__GetLocalPrivileges(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__GetMessageFromStandardConnection(CNetLayerInternal* thisPtr, int32_t*, char**, int32_t*);
int32_t CNetLayerInternal__GetNumberLocalAdapters(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__GetPasswordRequired(CNetLayerInternal* thisPtr);
CExoString CNetLayerInternal__GetPlayerAddress(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__GetPlayerAddressData(CNetLayerInternal* thisPtr, uint32_t, uint32_t*, unsigned char**, unsigned char**, uint32_t*);
CExoString CNetLayerInternal__GetPlayerPassword(CNetLayerInternal* thisPtr);
uint32_t CNetLayerInternal__GetPortBySessionId(CNetLayerInternal* thisPtr, uint32_t);
uint32_t CNetLayerInternal__GetSendUDPSocket(CNetLayerInternal* thisPtr);
CExoString CNetLayerInternal__GetServerAdminPassword(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__GetServerConnected(CNetLayerInternal* thisPtr);
CExoString CNetLayerInternal__GetServerNetworkAddress(CNetLayerInternal* thisPtr);
uint32_t CNetLayerInternal__GetServerPlayerCount(CNetLayerInternal* thisPtr);
CNetLayerSessionInfo* CNetLayerInternal__GetSessionInfo(CNetLayerInternal* thisPtr, uint32_t);
uint32_t CNetLayerInternal__GetSessionMaxPlayers(CNetLayerInternal* thisPtr);
CExoString CNetLayerInternal__GetSessionName(CNetLayerInternal* thisPtr);
uint32_t CNetLayerInternal__GetUDPRecievePort(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__GetWindowSendIdByReceiveId(CNetLayerInternal* thisPtr, uint32_t, uint32_t*);
int32_t CNetLayerInternal__HandleBNCRMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNCSMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNDMMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNDPMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNDRMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNDSMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNERMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNESMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNLMMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNLRMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNVRMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNVSMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNXIMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__HandleBNXRMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__Initialize(CNetLayerInternal* thisPtr, CBaseExoApp*);
int32_t CNetLayerInternal__IsConnectedToLocalhost(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__IsPlayerIpSameAsConnection(CNetLayerInternal* thisPtr, uint32_t, uint32_t);
int32_t CNetLayerInternal__MessageArrived(CNetLayerInternal* thisPtr, uint32_t, uint32_t, uint32_t, int32_t);
int32_t CNetLayerInternal__NonWindowMessages(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__OpenStandardConnection(CNetLayerInternal* thisPtr, int32_t, CExoString, int32_t);
int32_t CNetLayerInternal__PacketizeSendMessageToPlayer(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t, uint32_t);
int32_t CNetLayerInternal__PacketizeSmallMessageToPlayer(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t, uint32_t);
int32_t CNetLayerInternal__PlacePacketInSendQueues(CNetLayerInternal* thisPtr, uint32_t, int32_t, unsigned char*, uint32_t, int32_t);
int32_t CNetLayerInternal__PlayerIdToConnectionId(CNetLayerInternal* thisPtr, uint32_t, uint32_t*);
int32_t CNetLayerInternal__PlayerIdToSlidingWindow(CNetLayerInternal* thisPtr, uint32_t, uint32_t*);
void CNetLayerInternal__ProcessReceivedFrames(CNetLayerInternal* thisPtr, int32_t);
int32_t CNetLayerInternal__PurgeConnections(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__RequestExtendedServerInfo(CNetLayerInternal* thisPtr, uint32_t, int32_t, int32_t);
void CNetLayerInternal__ResetEnumerateSessionsList(CNetLayerInternal* thisPtr, unsigned char);
int32_t CNetLayerInternal__SendBNCRMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char, uint32_t);
int32_t CNetLayerInternal__SendBNCSMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char, int32_t, int32_t, const CExoString&, const CExoString&, const CExoString&, uint32_t&);
void CNetLayerInternal__SendBNDMMessage(CNetLayerInternal* thisPtr);
void CNetLayerInternal__SendBNDPMessage(CNetLayerInternal* thisPtr, uint32_t, uint32_t);
int32_t CNetLayerInternal__SendBNDSMessage(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__SendBNESDirectMessageToAddress(CNetLayerInternal* thisPtr, CExoString, unsigned char);
int32_t CNetLayerInternal__SendBNLMMessage(CNetLayerInternal* thisPtr, uint32_t, uint32_t);
int32_t CNetLayerInternal__SendBNVRMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char);
int32_t CNetLayerInternal__SendBNVSMessage(CNetLayerInternal* thisPtr, const CExoArrayListTemplatedCExoString*, const CExoString&, const CExoString&);
int32_t CNetLayerInternal__SendDirectMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t, uint32_t, uint32_t);
int32_t CNetLayerInternal__SendMessageToAddress(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__SendMessageToPlayer(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t, uint32_t);
int32_t CNetLayerInternal__SendMessageToStandardConnection(CNetLayerInternal* thisPtr, int32_t, char*, int32_t);
int32_t CNetLayerInternal__SetGameMasterPassword(CNetLayerInternal* thisPtr, CExoString);
void CNetLayerInternal__SetMasterServerInternetAddress(CNetLayerInternal* thisPtr, const unsigned char*, uint32_t);
uint32_t CNetLayerInternal__SetNetworkAddressData(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, unsigned char*, uint32_t);
void CNetLayerInternal__SetPlayerConnected(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__SetPlayerPassword(CNetLayerInternal* thisPtr, CExoString);
int32_t CNetLayerInternal__SetServerAdminPassword(CNetLayerInternal* thisPtr, CExoString);
void CNetLayerInternal__SetServerLanguage(CNetLayerInternal* thisPtr, int32_t);
void CNetLayerInternal__SetSessionMaxPlayers(CNetLayerInternal* thisPtr, uint32_t);
void CNetLayerInternal__SetSessionName(CNetLayerInternal* thisPtr, CExoString);
int32_t CNetLayerInternal__SetSlidingWindow(CNetLayerInternal* thisPtr, uint32_t, uint32_t, uint32_t*);
void CNetLayerInternal__SetUpPlayBackConnection(CNetLayerInternal* thisPtr);
int32_t CNetLayerInternal__ShutDown(CNetLayerInternal* thisPtr);
void CNetLayerInternal__ShutDownClientInterfaceWithReason(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__StartConnectToSession(CNetLayerInternal* thisPtr, uint32_t, const CExoString&, int32_t, int32_t, const CExoString&, uint32_t, uint32_t, const CExoString&, const CExoString&);
int32_t CNetLayerInternal__StartEnumerateSessions(CNetLayerInternal* thisPtr, uint32_t, int32_t, unsigned char*, uint16_t, int32_t, uint32_t);
int32_t CNetLayerInternal__StartEnumerateSessionsSection(CNetLayerInternal* thisPtr, uint32_t, uint32_t, CExoString*);
int32_t CNetLayerInternal__StartInternetAddressTranslation(CNetLayerInternal* thisPtr, CExoString, uint32_t, uint32_t);
int32_t CNetLayerInternal__StartPing(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__StartProtocol(CNetLayerInternal* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t);
int32_t CNetLayerInternal__StartServerMode(CNetLayerInternal* thisPtr, CExoString, uint32_t);
void CNetLayerInternal__StoreMessage(CNetLayerInternal* thisPtr, unsigned char*, uint32_t);
int32_t CNetLayerInternal__UncompressMessage(CNetLayerInternal* thisPtr, uint32_t, unsigned char*, uint32_t);
int32_t CNetLayerInternal__UpdateStatusLoop(CNetLayerInternal* thisPtr, uint32_t);
int32_t CNetLayerInternal__ValidatePlayerAgainstLastSuccessfulLogin(CNetLayerInternal* thisPtr, CExoString, CExoString);

}

}