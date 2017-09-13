#include "STDInc.h"

// Steam information.
char			Global::Variables::Steam_Username[16]{};
char			Global::Variables::Steam_Password[64]{};
char			Global::Variables::Steam_Language[16]{};
uint64_t		Global::Variables::Steam_UserID = 0;
bool			Global::Variables::Steam_Offline = false;
bool			Global::Variables::Steam_Dedicated = false;
uint32_t		Global::Variables::Steam_AppID = 0;
int				Global::Variables::Onlines = 0;

GameVersion		Global::Game::Version = GAME_VERSION_ERROR;
GameType		Global::Game::Type = GAME_TYPE_ERROR;
bool			Global::Game::Offline;
// Performance.
std::chrono::high_resolution_clock::time_point Global::Variables::StartupPoint = std::chrono::high_resolution_clock::now();