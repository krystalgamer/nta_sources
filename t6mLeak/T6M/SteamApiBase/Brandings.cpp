#include "STDInc.h"

int Brandings::BuildNumber = 41;

const char*	Brandings::GameWindowCaption;
const char*	Brandings::UI_BuildNumberText;
const char*	Brandings::ConsoleWindowCaption;

dvar_t* Brandings::r_noborder;


// Todo Fix the va to be overriden  happens if another va get called after seting the brandings to the correct value lol
void Brandings::Initialize()
{
	// Setup string's.
	Brandings::BuildNumber = Global::Game::Version;
	Brandings::GameWindowCaption = hString::va("PlusOps II %s V%i %s", Global::Game::Type == GameType::GAME_TYPE_MP ? "Multiplayer" : (Global::Game::Type == GameType::GAME_TYPE_ZM ? "Zombies" : (Global::Game::Type == GameType::GAME_TYPE_DEDI ? "Deticated" : "Error")), Brandings::BuildNumber, Global::Game::Offline ? "Offline" : "Online");
	Brandings::UI_BuildNumberText = hString::va("^2%s", Brandings::GameWindowCaption);
	Brandings::ConsoleWindowCaption = hString::va("%s - Console", Brandings::GameWindowCaption);





	// Change Version to my Version
	//*(const char**)Addresses::UI_BuildNumber = Brandings::UI_BuildNumberText;
	
	// Change Window Title
	*(const char**)Addresses::GameWindowName1 = Brandings::GameWindowCaption;
	*(const char**)Addresses::GameWindowName2 = Brandings::GameWindowCaption;

	// Change Console Title
	*(const char**)Addresses::ConsoleWindowName = Brandings::ConsoleWindowCaption;

	// No borderer
	*(DWORD*)Addresses::GameWindowStyle1 = WS_CAPTION;//WS_DLGFRAME -> Framte  WS_GROUP || WS_OVERLAPPED || WS_SYSMENU -> iw4play style // WS_CAPTION -> No border
	*(DWORD*)Addresses::GameWindowStyle2 = WS_CAPTION;//WS_DLGFRAME -> Framte  WS_GROUP || WS_OVERLAPPED || WS_SYSMENU -> iw4play style // WS_CAPTION -> No border
	
	// Also add dvar for this :P sadly there is no function to overwrite and tell him if dvar is active use no border but still not bad, and now i wanna go sleep
	Brandings::r_noborder = Addresses::Dvar_RegisterBool("r_noborder", false, DVAR_ARCHIVE, "Do not use a border in windowed mode");
}