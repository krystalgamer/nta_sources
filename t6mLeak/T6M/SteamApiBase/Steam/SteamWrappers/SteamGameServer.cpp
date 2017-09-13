#include "..\..\StdInc.h"
bool SteamGameServer011::InitGameServer(uint32 unGameIP, uint16 unGamePort, uint16 usQueryPort, uint32 unServerFlags, AppId_t nAppID, const char *pchVersion)
{
    return ProxiedGameServer::InitGameServer(unGameIP, unGamePort, usQueryPort, unServerFlags, nAppID, pchVersion);
}
void SteamGameServer011::SetProduct(const char *pchProductName)
{
    ProxiedGameServer::SetProduct(pchProductName);
}
void SteamGameServer011::SetGameDescription(const char *pchGameDescription)
{
    ProxiedGameServer::SetGameDescription(pchGameDescription);
}
void SteamGameServer011::SetModDir(const char *pchModDir)
{
    ProxiedGameServer::SetModDir(pchModDir);
}
void SteamGameServer011::SetDedicatedServer(bool bDedicatedServer)
{
    ProxiedGameServer::SetDedicatedServer(bDedicatedServer);
}

void SteamGameServer011::LogOn(const char *pszAccountName, const char *pszPassword)
{
    ProxiedGameServer::LogOn(pszAccountName, pszPassword);
}
void SteamGameServer011::LogOnAnonymous()
{
    ProxiedGameServer::LogOnAnonymous();
}
void SteamGameServer011::LogOff()
{
    ProxiedGameServer::LogOff();
}
bool SteamGameServer011::BLoggedOn()
{
    return ProxiedGameServer::BLoggedOn();
}
bool SteamGameServer011::BSecure()
{
    return ProxiedGameServer::BSecure();
}
CSteamID SteamGameServer011::GetSteamID()
{
    return ProxiedGameServer::GetSteamID();
}
bool SteamGameServer011::WasRestartRequested()
{
    return ProxiedGameServer::WasRestartRequested();
}

void SteamGameServer011::SetMaxPlayerCount(int cPlayersMax)
{
    ProxiedGameServer::SetMaxPlayerCount(cPlayersMax);
}
void SteamGameServer011::SetBotPlayerCount(int cBotPlayers)
{
    ProxiedGameServer::SetBotPlayerCount(cBotPlayers);
}
void SteamGameServer011::SetServerName(const char *pszServerName)
{
    ProxiedGameServer::SetServerName(pszServerName);
}
void SteamGameServer011::SetMapName(const char *pszMapName)
{
    ProxiedGameServer::SetMapName(pszMapName);
}
void SteamGameServer011::SetPasswordProtected(bool bPasswordProtected)
{
    ProxiedGameServer::SetPasswordProtected(bPasswordProtected);
}
void SteamGameServer011::SetSpectatorPort(uint16 unSpectatorPort)
{
    ProxiedGameServer::SetSpectatorPort(unSpectatorPort);
}
void SteamGameServer011::SetSpectatorServerName(const char *pszSpectatorServerName)
{
    ProxiedGameServer::SetSpectatorServerName(pszSpectatorServerName);
}
void SteamGameServer011::ClearAllKeyValues()
{
    ProxiedGameServer::ClearAllKeyValues();
}
void SteamGameServer011::SetKeyValue(const char *pKey, const char *pValue)
{
    ProxiedGameServer::SetKeyValue(pKey, pValue);
}
void SteamGameServer011::SetGameTags(const char *pchGameTags)
{
    ProxiedGameServer::SetGameTags(pchGameTags);
}
void SteamGameServer011::SetGameData(const char *pchGameData)
{
    ProxiedGameServer::SetGameData(pchGameData);
}
void SteamGameServer011::SetRegion(const char *pchRegionName)
{
    ProxiedGameServer::SetRegion(pchRegionName);
}

int SteamGameServer011::SendUserConnectAndAuthenticate(uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser)
{
    return ProxiedGameServer::SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
}
CSteamID SteamGameServer011::CreateUnauthenticatedUserConnection()
{
    return ProxiedGameServer::CreateUnauthenticatedUserConnection();
}
void SteamGameServer011::SendUserDisconnect(CSteamID steamIDUser)
{
    ProxiedGameServer::SendUserDisconnect(steamIDUser);
}
bool SteamGameServer011::BUpdateUserData(CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore)
{
    return ProxiedGameServer::BUpdateUserData(steamIDUser, pchPlayerName, uScore);
}

HAuthTicket SteamGameServer011::GetAuthSessionTicket(void *pTicket, int cbMaxTicket, uint32 *pcbTicket)
{
    return ProxiedGameServer::GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
}
EBeginAuthSessionResult SteamGameServer011::BeginAuthSession(const void *pAuthTicket, int cbAuthTicket, CSteamID steamID)
{
    return ProxiedGameServer::BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
}
void SteamGameServer011::EndAuthSession(CSteamID steamID)
{
    ProxiedGameServer::EndAuthSession(steamID);
}
void SteamGameServer011::CancelAuthTicket(HAuthTicket hAuthTicket)
{
    ProxiedGameServer::CancelAuthTicket(hAuthTicket);
}
EUserHasLicenseForAppResult SteamGameServer011::UserHasLicenseForApp(CSteamID steamID, AppId_t appID)
{
    return ProxiedGameServer::UserHasLicenseForApp(steamID, appID);
}
bool SteamGameServer011::RequestUserGroupStatus(CSteamID steamIDUser, CSteamID steamIDGroup)
{
    return ProxiedGameServer::RequestUserGroupStatus(steamIDUser, steamIDGroup);
}

void SteamGameServer011::GetGameplayStats()
{
    ProxiedGameServer::GetGameplayStats();
}
SteamAPICall_t SteamGameServer011::GetServerReputation()
{
    return ProxiedGameServer::GetServerReputation();
}
uint32 SteamGameServer011::GetPublicIP()
{
    return ProxiedGameServer::GetPublicIP();
}
bool SteamGameServer011::HandleIncomingPacket(const void *pData, int cbData, uint32 srcIP, uint16 srcPort)
{
    return ProxiedGameServer::HandleIncomingPacket(pData, cbData, srcIP, srcPort);
}
int SteamGameServer011::GetNextOutgoingPacket(void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort)
{
    return ProxiedGameServer::GetNextOutgoingPacket(pOut, cbMaxOut, pNetAdr, pPort);
}
void SteamGameServer011::EnableHeartbeats(bool bActive)
{
    ProxiedGameServer::EnableHeartbeats(bActive);
}
void SteamGameServer011::SetHeartbeatInterval(int iHeartbeatInterval)
{
    ProxiedGameServer::SetHeartbeatInterval(iHeartbeatInterval);
}
void SteamGameServer011::ForceHeartbeat()
{
    ProxiedGameServer::ForceHeartbeat();
}
SteamAPICall_t SteamGameServer011::AssociateWithClan(CSteamID clanID)
{
    return ProxiedGameServer::AssociateWithClan(clanID);
}
SteamAPICall_t SteamGameServer011::ComputeNewPlayerCompatibility(CSteamID steamID)
{
    return ProxiedGameServer::ComputeNewPlayerCompatibility(steamID);
}