#include "..\..\StdInc.h"
int SteamMatchmaking009::GetFavoriteGameCount()
{
	return ProxiedMatchmaking::GetFavoriteGameCount();
}
bool SteamMatchmaking009::GetFavoriteGame(int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer)
{
	return ProxiedMatchmaking::GetFavoriteGame(iGame, pnAppID, pnIP, pnConnPort, 0, punFlags, pRTime32LastPlayedOnServer);
}
int SteamMatchmaking009::AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer)
{
	return ProxiedMatchmaking::AddFavoriteGame(nAppID, nIP, nConnPort, 0, unFlags, rTime32LastPlayedOnServer);
}
bool SteamMatchmaking009::RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags)
{
	return ProxiedMatchmaking::RemoveFavoriteGame(nAppID, nIP, nConnPort, 0, unFlags);
}
SteamAPICall_t SteamMatchmaking009::RequestLobbyList()
{
	return ProxiedMatchmaking::RequestLobbyList();
}
void SteamMatchmaking009::AddRequestLobbyListStringFilter(const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType)
{
	return ProxiedMatchmaking::AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, ELobbyComparison::k_ELobbyComparisonEqual);
}
void SteamMatchmaking009::AddRequestLobbyListNumericalFilter(const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType)
{
	return ProxiedMatchmaking::AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
}
void SteamMatchmaking009::AddRequestLobbyListNearValueFilter(const char *pchKeyToMatch, int nValueToBeCloseTo)
{
	return ProxiedMatchmaking::AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
}
void SteamMatchmaking009::AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable)
{
	return ProxiedMatchmaking::AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
}
void SteamMatchmaking009::AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter)
{
	return ProxiedMatchmaking::AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
}
void SteamMatchmaking009::AddRequestLobbyListResultCountFilter(int cMaxResults)
{
	return ProxiedMatchmaking::AddRequestLobbyListResultCountFilter(cMaxResults);
}
void SteamMatchmaking009::AddRequestLobbyListCompatibleMembersFilter(CSteamID steamID)
{
	return ProxiedMatchmaking::AddRequestLobbyListCompatibleMembersFilter(steamID);
}
CSteamID SteamMatchmaking009::GetLobbyByIndex(int iLobby)
{
	return ProxiedMatchmaking::GetLobbyByIndex(iLobby);
}
SteamAPICall_t SteamMatchmaking009::CreateLobby(ELobbyType eLobbyType, int cMaxMembers)
{
	return ProxiedMatchmaking::CreateLobby(eLobbyType, cMaxMembers);
}
SteamAPICall_t SteamMatchmaking009::JoinLobby(CSteamID steamIDLobby)
{
	return ProxiedMatchmaking::JoinLobby(steamIDLobby);
}
void SteamMatchmaking009::LeaveLobby(CSteamID steamIDLobby)
{
	return ProxiedMatchmaking::LeaveLobby(steamIDLobby);
}
bool SteamMatchmaking009::InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee)
{
	return ProxiedMatchmaking::InviteUserToLobby(steamIDLobby, steamIDInvitee);
}
int SteamMatchmaking009::GetNumLobbyMembers(CSteamID steamIDLobby)
{
	return ProxiedMatchmaking::GetNumLobbyMembers(steamIDLobby);
}
CSteamID SteamMatchmaking009::GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember)
{
	return ProxiedMatchmaking::GetLobbyMemberByIndex(steamIDLobby, iMember);
}
const char* SteamMatchmaking009::GetLobbyData(CSteamID steamIDLobby, const char *pchKey)
{
	return ProxiedMatchmaking::GetLobbyData(steamIDLobby, pchKey);
}
bool SteamMatchmaking009::SetLobbyData(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
{
	return ProxiedMatchmaking::SetLobbyData(steamIDLobby, pchKey, pchValue);
}
int SteamMatchmaking009::GetLobbyDataCount(CSteamID steamIDLobby)
{
	return ProxiedMatchmaking::GetLobbyDataCount(steamIDLobby);
}
bool SteamMatchmaking009::GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize)
{
	return ProxiedMatchmaking::GetLobbyDataByIndex(steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
}
bool SteamMatchmaking009::DeleteLobbyData(CSteamID steamIDLobby, const char *pchKey)
{
	return ProxiedMatchmaking::DeleteLobbyData(steamIDLobby, pchKey);
}
const char* SteamMatchmaking009::GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey)
{
	return ProxiedMatchmaking::GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey);
}
void SteamMatchmaking009::SetLobbyMemberData(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
{
	return ProxiedMatchmaking::SetLobbyMemberData(steamIDLobby, pchKey, pchValue);
}
bool SteamMatchmaking009::SendLobbyChatMsg(CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody)
{
	return ProxiedMatchmaking::SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody);
}
int SteamMatchmaking009::GetLobbyChatEntry(CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType)
{
	return ProxiedMatchmaking::GetLobbyChatEntry(steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
}
bool SteamMatchmaking009::RequestLobbyData(CSteamID steamIDLobby)
{
	return ProxiedMatchmaking::RequestLobbyData(steamIDLobby);
}
void SteamMatchmaking009::SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer)
{
	ProxiedMatchmaking::SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
}
bool SteamMatchmaking009::GetLobbyGameServer(CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, CSteamID *psteamIDGameServer)
{
	return ProxiedMatchmaking::GetLobbyGameServer(steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
}
bool SteamMatchmaking009::SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers)
{
	return ProxiedMatchmaking::SetLobbyMemberLimit(steamIDLobby, cMaxMembers);
}
int SteamMatchmaking009::GetLobbyMemberLimit(CSteamID steamIDLobby)
{
	return ProxiedMatchmaking::GetLobbyMemberLimit(steamIDLobby);
}
bool SteamMatchmaking009::SetLobbyType(CSteamID steamIDLobby, ELobbyType eLobbyType)
{
	return ProxiedMatchmaking::SetLobbyType(steamIDLobby, eLobbyType);
}
bool SteamMatchmaking009::SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable)
{
	return ProxiedMatchmaking::SetLobbyJoinable(steamIDLobby, bLobbyJoinable);
}
CSteamID SteamMatchmaking009::GetLobbyOwner(CSteamID steamIDLobby)
{
	return ProxiedMatchmaking::GetLobbyOwner(steamIDLobby);
}
bool SteamMatchmaking009::SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner)
{
	return ProxiedMatchmaking::SetLobbyOwner(steamIDLobby, steamIDNewOwner);
}
bool SteamMatchmaking009::SetLinkedLobby(CSteamID steamIDLobby, CSteamID steamIDLobby2)
{
	return ProxiedMatchmaking::SetLinkedLobby(steamIDLobby, steamIDLobby2);
}