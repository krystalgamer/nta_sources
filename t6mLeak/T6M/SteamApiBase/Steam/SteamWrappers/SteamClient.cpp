#include "..\..\StdInc.h"
HSteamPipe SteamClient012::CreateSteamPipe()
{
	return 1;
}
bool SteamClient012::BReleaseSteamPipe(HSteamPipe hSteamPipe)
{
	return true;
}
HSteamUser SteamClient012::ConnectToGlobalUser(HSteamPipe hSteamPipe)
{
	return NULL;
}
HSteamUser SteamClient012::CreateLocalUser(HSteamPipe *phSteamPipe, EAccountType eAccountType)
{
	return NULL;
}
void SteamClient012::ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hUser)
{

}
ISteamUser *SteamClient012::GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamUser();
}
ISteamGameServer *SteamClient012::GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamGameServer();
}
void SteamClient012::SetLocalIPBinding(uint32 unIP, uint16 usPort)
{
	_ReturnAddress();
}
ISteamFriends *SteamClient012::GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamFriends();
}
ISteamUtils *SteamClient012::GetISteamUtils(HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamUtils();
}
ISteamMatchmaking *SteamClient012::GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamMatchmaking();
}
ISteamMatchmakingServers *SteamClient012::GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamMatchmakingServers();
}
void *SteamClient012::GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return NULL;
}
ISteamUserStats *SteamClient012::GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamUserStats();
}
ISteamGameServerStats *SteamClient012::GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamGameServerStats();
}
ISteamApps *SteamClient012::GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamApps();
}
ISteamNetworking *SteamClient012::GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamNetworking();
}
ISteamRemoteStorage *SteamClient012::GetISteamRemoteStorage(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamRemoteStorage();
}
ISteamScreenshots *SteamClient012::GetISteamScreenshots(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamScreenshots();
}
void SteamClient012::RunFrame()
{

}
uint32 SteamClient012::GetIPCCallCount()
{
	return 1338;
}
void SteamClient012::SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction)
{

}
bool SteamClient012::BShutdownIfAllPipesClosed()
{
	return true;
}
ISteamHTTP* SteamClient012::GetISteamHTTP(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamHTTP();
}
ISteamUnifiedMessages* SteamClient012::GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamUnifiedMessages();
}
ISteamController* SteamClient012::GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
{
	return SteamCommon::GetSteamController();
}