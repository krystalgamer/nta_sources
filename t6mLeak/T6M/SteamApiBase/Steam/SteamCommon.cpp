#include "..\STDInc.h"

HMODULE SteamCommon::SteamOverlay = 0;
char SteamCommon::SteamPath[MAX_PATH] = { 0 };


static SteamApps005* _SteamApps = new SteamApps005;
static SteamClient012* _SteamClient = new SteamClient012;
static SteamFriends013* _SteamFriends = new SteamFriends013;
static SteamContentServer002* _SteamContentServer = new SteamContentServer002;
static SteamGameServer011* _SteamGameServer = new SteamGameServer011;
static SteamHTTP001* _SteamHTTP = new SteamHTTP001;
static SteamMatchmaking009* _SteamMatchMaking = new SteamMatchmaking009;
static SteamMatchmakingServers002* _SteamMatchMakingServers = new SteamMatchmakingServers002;
static SteamNetworking005* _SteamNetworking = new SteamNetworking005;
static SteamRemoteStorage008* _SteamRemoteStorage = new SteamRemoteStorage008;
static SteamUser016* _SteamUser = new SteamUser016;
static SteamUserStats011* _SteamUserStats = new SteamUserStats011;
static SteamUtils005* _SteamUtils = new SteamUtils005;


bool ValueExists(char *Section, char *Key, char *File)
{
	char Buffer[512];
	if (GetPrivateProfileString(Section, Key, NULL, Buffer, 512, File) > 0)
		return true;
	return false;
}
void SteamCommon::Init()
{
	//HHSDBG();
	char Buffer[512];
	char Path[512] = ".\\" USERDATA_PATH "\\GameSettings.ini";
	if (GetPrivateProfileString("Settings", "Username", "Unknown", Buffer, 512, Path) > 0)
	{
		strcpy(Global::Variables::Steam_Username, Buffer);
	}
	if (GetPrivateProfileString("Settings", "Password", "123456", Buffer, 512, Path) > 0)
	{
		strcpy(Global::Variables::Steam_Password, Buffer);
	}
	if (GetPrivateProfileString("Settings", "Language", "english", Buffer, 512, Path) > 0)
	{
		strcpy(Global::Variables::Steam_Language, Buffer);
	}

	xNP_Initiate();

	if (!xNP_Connect(MASTER_SERVER, 14030))
	{
		Addresses::Com_Error(ERR_FROM_STARTUP, "Could not connect to 'SONSORED' Server at " MASTER_SERVER);
	}



	xNPAuthenticateResult* result;

	xNPAsync<xNPAuthenticateResult>* async = xNP_CreateSessionWithCredentials(Global::Variables::Steam_Username, Global::Variables::Steam_Password, Global::Variables::Steam_Username);
	//xNPAsync<xNPAuthenticateResult>* async = xNP_CreateSessionWithKey("1234567890abcdefghjklmnopqrstwxyz");
	result = async->Wait();



	if (result->result != AuthenticateResultOK)
	{
		switch (result->result)
		{
		case AuthenticateResultBadDetails:
			Addresses::Com_Error(ERR_FROM_STARTUP,  "Could not authenticate to 'SONSORED' at " MASTER_SERVER " -- bad details | wrong username and password.");
			break;
		case AuthenticateResultAlreadyLoggedIn:
			Addresses::Com_Error(ERR_FROM_STARTUP,  "Could not authenticate to 'SONSORED' at " MASTER_SERVER " -- already logged in.");
			break;
		case AuthenticateResultServiceUnavailable:
			Addresses::Com_Error(ERR_FROM_STARTUP,  "Could not authenticate to 'SONSORED' at " MASTER_SERVER " -- service unavailable.");
			break;
		case AuthenticateResultBanned:
			Addresses::Com_Error(ERR_FROM_STARTUP,  "Could not authenticate to 'SONSORED' at " MASTER_SERVER " -- banned.");
			break;
		case AuthenticateResultUnknown:
			Addresses::Com_Error(ERR_FROM_STARTUP,  "Could not authenticate to 'SONSORED' at " MASTER_SERVER " -- unknown error.");
			break;
		}

	}

	
	xNP_SetRichPresence("currentGame", "t6mp");
	xNP_SetRichPresenceBody("Playing T6MP");
	xNP_StoreRichPresence();

	xNPAsync<xNPGetOnlineFriensResult>* async2 = xNP_GetOnlinePlayers("pt6");

	Global::Variables::Onlines = async2->Wait()->TotalOnlines;


	//steamID = new CSteamID(0x1100001DEADC0DE, EUniverse::k_EUniversePublic, EAccountType::k_EAccountTypeIndividual);
}
void SteamCommon::SetSteamDirectory()
{
	HKEY hRegKey;
	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, STEAM_REGISTRY_PATH, 0, KEY_QUERY_VALUE, &hRegKey) == ERROR_SUCCESS)
	{
		DWORD dwLength = sizeof(SteamCommon::SteamPath);
		RegQueryValueExA(hRegKey, "InstallPath", NULL, NULL, (BYTE*)SteamCommon::SteamPath, &dwLength);
		RegCloseKey(hRegKey);
		SetDllDirectory(SteamCommon::SteamPath);
	}
}
void SteamCommon::LoadOverlay()
{
	if (!*SteamCommon::SteamPath) SteamCommon::SetSteamDirectory();
	SteamCommon::SteamOverlay = GetModuleHandleA(GAMEOVERLAY_LIB);
	if (!SteamCommon::SteamOverlay)
	{
		SteamCommon::SteamOverlay = LoadLibraryA(GAMEOVERLAY_LIB);
	}
}

SteamAPICall_t SteamCommon::RequestEncryptedAppTicket(const void *pUserData, int cbUserData)
{
	//HHSDBG();
	uint64 userID = GetSteamID()->ConvertToUint64();
	memset(encryptedAppTicket, 0, sizeof(encryptedAppTicket));
	memcpy(&encryptedAppTicket[32], pUserData, min(cbUserData, sizeof(encryptedAppTicket)));
	memcpy(&encryptedAppTicket[cbUserData + 32], &userID, sizeof(userID));
	SteamAPICall_t callID = SteamCallback::RegisterCall();
	EncryptedAppTicketResponse_t *response = (EncryptedAppTicketResponse_t*)malloc(sizeof(EncryptedAppTicketResponse_t));
	response->m_eResult = k_EResultOK;
	return callID;
}
CSteamID *SteamCommon::GetSteamID()
{
	xNPID myid;
	xNP_GetxNPID(&myid);
	return &CSteamID(myid);
}
AppId_t SteamCommon::GetSteamAppID()
{
	return Global::Variables::Steam_AppID;
}
char *SteamCommon::GetEncryptedAppTicket()
{
	//HHSDBG();
	return encryptedAppTicket;
}
char *SteamCommon::GetPlayerName()
{
	//HHSDBG();
	return Global::Variables::Steam_Username;
}
void SteamCommon::SetPlayerName(const char *newName)
{
	//HHSDBG();
	strcpy(Global::Variables::Steam_Username, newName);
}
ISteamApps *SteamCommon::GetSteamApps()
{
	return (ISteamApps*)_SteamApps;
}
ISteamFriends *SteamCommon::GetSteamFriends()
{
	return (ISteamFriends*)_SteamFriends;
}
ISteamClient *SteamCommon::GetSteamClient()
{
	return (ISteamClient *)_SteamClient;
}
ISteamGameServer *SteamCommon::GetSteamGameServer()
{
	return (ISteamGameServer *)_SteamGameServer;
}
ISteamGameServerStats *SteamCommon::GetSteamGameServerStats()
{
	//HHSDBG();
	return NULL;// (ISteamGameServerStats *)InterfaceManager::GetInterface(_SteamGameServerStats);
}
ISteamHTTP *SteamCommon::GetSteamHTTP()
{
	//HHSDBG();
	return (ISteamHTTP*)_SteamHTTP;
}
ISteamMatchmaking *SteamCommon::GetSteamMatchmaking()
{
	//HHSDBG();
	return (ISteamMatchmaking *)_SteamMatchMaking;
}
ISteamMatchmakingServers *SteamCommon::GetSteamMatchmakingServers()
{
	//HHSDBG();
	return (ISteamMatchmakingServers *)_SteamMatchMakingServers;
}
ISteamNetworking *SteamCommon::GetSteamNetworking()
{
	//HHSDBG();
	return (ISteamNetworking*)_SteamNetworking;
}
ISteamRemoteStorage *SteamCommon::GetSteamRemoteStorage()
{
	//HHSDBG();
	return (ISteamRemoteStorage*)_SteamRemoteStorage;
}
ISteamUser *SteamCommon::GetSteamUser()
{
	return (ISteamUser*)_SteamUser;
}
ISteamUserStats *SteamCommon::GetSteamUserStats()
{
	//HHSDBG();
	return (ISteamUserStats *)_SteamUserStats;
}
ISteamUtils *SteamCommon::GetSteamUtils()
{
	////HHSDBG();
	return (ISteamUtils *)_SteamUtils;
}
ISteamBilling *SteamCommon::GetSteamBilling()
{
	//HHSDBG();
	//return (ISteamBilling *)InterfaceManager::GetInterface(_steam);
	return NULL;
}
ISteamContentServer *SteamCommon::GetSteamContentServer()
{
	//HHSDBG();
	return (ISteamContentServer *)_SteamContentServer;
}
ISteamMasterServerUpdater *SteamCommon::GetSteamMasterServerUpdater()
{
	//HHSDBG();
	//return (ISteamMasterServerUpdater *)InterfaceManager::GetInterface(_masterserv);
	return NULL;
}
ISteamController *SteamCommon::GetSteamController()
{
	//HHSDBG();
	return NULL;//(ISteamController *)InterfaceManager::GetInterface(_SteamController);
}
ISteamScreenshots *SteamCommon::GetSteamScreenshots()
{
	//HHSDBG();
	return NULL;//(ISteamScreenshots *)InterfaceManager::GetInterface(_SteamScreenshots);
}
ISteamUnifiedMessages *SteamCommon::GetSteamUnifiedMessages()
{
	//HHSDBG();
	return NULL;//(ISteamUnifiedMessages *)InterfaceManager::GetInterface(_SteamUnifiedMessages);
}

CSteamID *SteamCommon::steamID = NULL;
AppId_t SteamCommon::steamAppID = NULL;
char SteamCommon::encryptedAppTicket[128];