// General includes.


#pragma once

#define DEVBUILD

#ifndef WIN32_LEAN_AND_MEAN
#define	WIN32_LEAN_AND_MEAN
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define	_CRT_SECURE_NO_WARNINGS
#endif

#ifdef DEVBUILD
#define HHSDBG() Log::Debug("SteamApiBase", "%s()", __FUNCTION__)
#else
#define HHSDBG()
#endif

// C\C++ includes.
#pragma region Runtime
//#include <Windows.h>
#include <string>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <sys/stat.h>
#include <list>
#include <map>
#include <queue>
#include <fstream>
#include <unordered_map>
#include <memory>
#include <mutex>
#include <chrono>
#include <thread>
#include <direct.h>
#pragma endregion

#include <ws2tcpip.h>// yhea for server look at Entry.cpp and Server.cpp ther eis it too with backslash

#include "Steam\SteamCallback.h"

#include "Utils\Log.h"
#include "Steam\Steam.h"


#include "T6.h"
#include "DumpHandler.h"
#include "Hooking.h"
#include "Patch.h"
#include "FileIO.h"
#include "hString.h"
#include "Addresses.h"
#include "PatchT6MP.h"
#include "PatchT6ZM.h"
#include "Global.h"
#include "Patterns.h"
#include "Scriptability.h"
#include "Notify.h"
#include "Bots.h"
#include "Command.h"
#include "HudElem.h"
#include "MainPatchFunctions.h"
#include "ColoredName.h"
#include "InGameConsole.h"
#include "ServerList.h"
#include "Zone.h"
#include "Experimental.h"
#include "Brandings.h"
#include "DLC.h"
#include "Popup.h"
#include "GamePlay.h"

//My Structs stuff
#include "XModel.h"

//Server stuff
#include "libnp\libnp.h"
#include "Crypto.h"
#include "Entry.h"
#include "Auth.h"
#include "BitBuffer.h"
#include "ByteBuffer.h"
#include "dwMessage.h"
#include "TitleUtils.h"
#include "Storage.h"
#include "dw_Handler.h"
#include "bdProfile.h"

//match data
#include "bdMatchMakingInfo.h"
#include "dw_match.h"


#include "Server.h"
