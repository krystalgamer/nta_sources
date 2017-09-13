#pragma once
class ServerList
{
private:
	static Hook::Stomp GetServerNameFromListHook;
	static Hook::Stomp GetServerCountHook;
	static int ServerCount;
	static DWORD GetServerNameFromList(int Server);
	static int GetServerCount();
	static void WriteServerInformation(DWORD Server, const char* ServerName, const char* MapName, bool isInGame, int com_maxclients, int clients, int ping, int minping, int maxping, const char* gamemode);
	static void AddServer();
public:
	static void Initialize();
};