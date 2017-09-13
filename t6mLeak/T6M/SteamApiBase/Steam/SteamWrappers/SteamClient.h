#pragma once
class SteamClient012 : ISteamClient012
{
public:
	HSteamPipe CreateSteamPipe();
	bool BReleaseSteamPipe(HSteamPipe hSteamPipe);
	HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe);
	HSteamUser CreateLocalUser(HSteamPipe *phSteamPipe, EAccountType eAccountType);
	void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hUser);
	ISteamUser *GetISteamUser(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamGameServer *GetISteamGameServer(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	void SetLocalIPBinding(uint32 unIP, uint16 usPort);
	ISteamFriends *GetISteamFriends(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamUtils *GetISteamUtils(HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamMatchmaking *GetISteamMatchmaking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamMatchmakingServers *GetISteamMatchmakingServers(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	void *GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamUserStats *GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamGameServerStats *GetISteamGameServerStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamApps *GetISteamApps(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamNetworking *GetISteamNetworking(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamRemoteStorage *GetISteamRemoteStorage(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamScreenshots *GetISteamScreenshots(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion);
	void RunFrame();
	uint32 GetIPCCallCount();
	void SetWarningMessageHook(SteamAPIWarningMessageHook_t pFunction);
	bool BShutdownIfAllPipesClosed();
	ISteamHTTP* GetISteamHTTP(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamUnifiedMessages* GetISteamUnifiedMessages(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
	ISteamController* GetISteamController(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion);
};