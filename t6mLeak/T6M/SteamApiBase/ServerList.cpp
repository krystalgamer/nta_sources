#include "STDInc.h"
Hook::Stomp ServerList::GetServerNameFromListHook;
Hook::Stomp ServerList::GetServerCountHook;
int ServerList::ServerCount;


struct Server_t
{
	char pad[0x3D];//
	WORD MinPing;
	WORD MaxPing;
	WORD Ping;
	char pad2[0x48];//
	char ServerName[0x15];
};


//typedef dvar_t*(__cdecl* FindDvar_t)(const char*);
//FindDvar_t FindDvar = (FindDvar_t)0x8C6D80;


DWORD ServerList::GetServerNameFromList(int Server)
{
	//normaly address is ServerBaseAddress + 0x85 but i have change to 0x88 for some reasons its same LOL
	return *(DWORD*)((Addresses::ServerBaseAddress + 0x88) + 0x110 * Server);
}
int ServerList::GetServerCount()
{
	return ServerCount;
}
void ServerList::WriteServerInformation(DWORD Server, const char* ServerName, const char* MapName, bool isInGame, int com_maxclients, int clients, int ping, int minping, int maxping, const char* gamemode)
{	
	//// Testing using Struct.
	//Server_t* myServer = new Server_t();
	////myServer->ServerName = strdup(ServerName);
	////myServer->MapName = strdup(ServerName);
	//myServer->Ping = ping;
	//myServer->MaxPing = ping;
	//myServer->MinPing = ping;
	//return;


	//Server Name
	memcpy((void*)(Server + 0x88), ServerName, 0x15);

	//Mapname
	memcpy((void*)(Server + 0xA8), MapName, 0x15);

	//isInGame
	*(bool*)(Server + 0xF0) = isInGame;

	//com_maxclients
	*(DWORD*)(Server + 0x72) = com_maxclients;

	//Clients
	*(DWORD*)(Server + 0x71) = clients;

	//minping
	*((WORD*)Server + 0x3E) = minping;

	//maxping
	*((WORD*)Server + 0x3F) = maxping;

	//ping
	*((WORD*)Server + 0x40) = ping;

	//GameMode
	memcpy((void*)(Server + 0xE0), gamemode, 0x15);
}
void ServerList::AddServer()
{
	ServerList::ServerCount = 25;
	if (Global::Game::Type == GameType::GAME_TYPE_ZM)
	{
		for (int i = 0; i < ServerCount; i++)
			ServerList::WriteServerInformation(Addresses::ServerBaseAddress + (0x110 * i), hString::va("Test Server %i", i), "tomb_zm", (i == (i / 2) * 2 ? true : false), 18, 1, 80, 0, 140, "ZMUI_ZCLASSIC");
	}
	else
	{
		for (int i = 0; i < ServerCount; i++)
			ServerList::WriteServerInformation(Addresses::ServerBaseAddress + (0x110 * i), hString::va("Test Server %i", i), "mp_nuketown_2020", (i == (i / 2) * 2 ? true : false), 18, 1, 80, 0, 140, "tdm");
	}
}
void ServerList::Initialize()
{
	// seems to work but still its not DvarFind :P
	Addresses::Dvar_RegisterBool("ui_netSource", false, 0, "");
	// for some reasons it dosent find my dvar
	//FindDvar("ui_netSource");//return 0 ?!?!?!?


	ServerList::GetServerNameFromListHook.Initialize(Addresses::GetServerNameFromList, ServerList::GetServerNameFromList);
	ServerList::GetServerNameFromListHook.InstallHook();

	ServerList::GetServerCountHook.Initialize(Addresses::GetServerCount, ServerList::GetServerCount);
	ServerList::GetServerCountHook.InstallHook();

	// Lets add some Servers and set some assigne it.
	ServerList::AddServer();
}