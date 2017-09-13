#include "STDInc.h"
#include "CEG.h"

void Patch()
{
	switch (*(DWORD*)0x41136F)
	{
		// Version 39
		case 0x75C08500:
		{
			Global::Game::Version = GAME_VERSION_39;
			Global::Game::Type    = GAME_TYPE_ZM;
			break;
		}
		
		// Version 40
		case 0x111F9C35:
		{
			Global::Game::Version = GAME_VERSION_40;
			Global::Game::Type    = GAME_TYPE_MP;
			break;
		}

		// Version 41
		case 0x244C8BCC:
		{
			Global::Game::Version = GAME_VERSION_41;
			Global::Game::Type    = GAME_TYPE_ZM;
			break;
		}

		// Version 43
		case 0x30C4835E:
		{
			Global::Game::Version = GAME_VERSION_43;
			Global::Game::Type    = GAME_TYPE_MP;
			break;
		}
		// Dedicated - debug version
		case 0x0F0C7D8B:
		{
			Global::Game::Version = GAME_VERSION_DEDI_DEBUG;
			Global::Game::Type    = GAME_TYPE_DEDI;
			break;
		}
		default:
		{
			Global::Game::Version = GAME_VERSION_ERROR;
			Global::Game::Type    = GAME_TYPE_ERROR;
			break;
		}
	}

	// Fix Version 39 Zombies -> Start Match
	// Fix Brandings -> va override

	Addresses::Assign();							// Done
	SteamCommon::LoadOverlay();						// Done
	DumpHandler::Initialize();						// Done
	//Bots::Initialize();								// Done
	//ColoredName::Initialize();						// Try To Fix Other Colors abov ^7 and the last Char*
	//InGameConsole::Initialize();					// Color Fix and KeyEvent fix.
	ServerList::Initialize();						// Done.
	//Script::Initialize();							// Kinda Crash for sometime.
	//Experimental::Initialize();						// Still only shit in here.
	//Brandings::Initialize();						// Fix hString::va overriden
	//HudElements::Initialize();						// Done.
	//DLC::Initialize();								// Done.
	//GamePlay::Initialize();							// Kinda not finish? nope.
	CegHandler::Initialize();						// Done.
	Server::Initialize();							// Doing Shit now.
	//Zone::Initialize();


	if (Global::Game::Type == GAME_TYPE_ZM)
	{
		Global::Variables::Steam_AppID = 212910;
		if (Global::Game::Version == GAME_VERSION_39)
		{
			T6ZM::PatchT6ZM_V39();
		}
		else if (Global::Game::Version == GAME_VERSION_41)
		{
			T6ZM::PatchT6ZM_V41();
		}
	}
	else if (Global::Game::Type == GAME_TYPE_MP)
	{
		Global::Variables::Steam_AppID = 202990;
		if (Global::Game::Version == GAME_VERSION_40)
		{
			T6MP::PatchT6MP_V40();
		}
		else if (Global::Game::Version == GAME_VERSION_43)
		{
			T6MP::PatchT6MP_V43();
		}
	}
	else
	{
		Auth_Error("Game version not supported. Aborting startup");
		ExitProcess(0x8000D3AD);
	}
}