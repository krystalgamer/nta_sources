#pragma once
#define MIN_NAME_LENGTH 3
#define FRIEND_COUNT 5
// Game version definition
typedef enum GameVersion
{
	GAME_VERSION_39 = 39,
	GAME_VERSION_40 = 40,
	GAME_VERSION_41 = 41,
	GAME_VERSION_43 = 43,
	GAME_VERSION_DEDI_DEBUG,
	//GAME_VERSION_DEDI_SHIP,
	GAME_VERSION_ERROR = -1
};
// Game type definition
typedef enum GameType
{
	GAME_TYPE_MP,
	GAME_TYPE_ZM,
	GAME_TYPE_DEDI,
	GAME_TYPE_ERROR = -1
};
class Global
{
public:
	class Game
	{
	public:
		static GameVersion	Version;
		static GameType		Type;
		static bool			Offline;
	};
	class Variables
	{
	public:
		// Steam information.
		static char			Steam_Username[16];
		static char			Steam_Password[64];
		static char			Steam_Language[16];
		static uint64_t		Steam_UserID;
		static bool			Steam_Offline;
		static bool			Steam_Dedicated;
		static uint32_t		Steam_AppID;
		static int		Onlines;
		// Performance.
		static std::chrono::high_resolution_clock::time_point StartupPoint;
	};
};