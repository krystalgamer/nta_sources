//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================


#ifdef _WIN32
#pragma once
#endif

#if defined(__GNUC__) && defined(_WIN32)
// This ugly hack allows us to provide GCC compatibility on windows without much effort
#pragma push_macro("virtual")
#undef virtual
#define virtual virtual __thiscall
#endif

// client
#include "ISteamClient012.h"

// friends
#include "ISteamFriends013.h"

// screenshots
#include "ISteamScreenshots001.h"
#include "ISteamScreenshots002.h"

// user
#include "ISteamUser004.h"
#include "ISteamUser005.h"
#include "ISteamUser006.h"
#include "ISteamUser007.h"
#include "ISteamUser008.h"
#include "ISteamUser009.h"
#include "ISteamUser010.h"
#include "ISteamUser011.h"
#include "ISteamUser012.h"
#include "ISteamUser013.h"
#include "ISteamUser014.h"
#include "ISteamUser015.h"
#include "ISteamUser016.h"
#include "ISteamUser017.h"

// OAuth
#include "ISteamOAuth001.h"

// apps
#include "ISteamApps005.h"

// app list
#include "ISteamAppList001.h"

// user stats
#include "ISteamUserStats001.h"
#include "ISteamUserStats002.h"
#include "ISteamUserStats003.h"
#include "ISteamUserStats004.h"
#include "ISteamUserStats005.h"
#include "ISteamUserStats006.h"
#include "ISteamUserStats007.h"
#include "ISteamUserStats008.h"
#include "ISteamUserStats009.h"
#include "ISteamUserStats010.h"
#include "ISteamUserStats011.h"

// utils
#include "ISteamUtils001.h"
#include "ISteamUtils002.h"
#include "ISteamUtils003.h"
#include "ISteamUtils004.h"
#include "ISteamUtils005.h"
#include "ISteamUtils006.h"
#include "ISteamUtils007.h"

// game server
#include "ISteamGameServer011.h"

// master server updater
#include "ISteamMasterServerUpdater001.h"

// matchmaking
#include "ISteamMatchmaking009.h"

// matchmaking servers
#include "ISteamMatchmakingServers001.h"
#include "ISteamMatchmakingServers002.h"

// networking
#include "ISteamNetworking005.h"

// billing
#include "ISteamBilling001.h"
#include "ISteamBilling002.h"

// remote storage
#include "ISteamRemoteStorage008.h"

// content server
#include "ISteamContentServer002.h"

// steam 2 bridge
#include "ISteam2Bridge001.h"
#include "ISteam2Bridge002.h"

// game coordinator
#include "ISteamGameCoordinator001.h"

// game server stats
#include "ISteamGameServerStats001.h"

// game stats
#include "ISteamGameStats001.h"

// app ticket
#include "ISteamAppTicket001.h"

// http
#include "ISteamHTTP001.h"

// unified messages
#include "ISteamUnifiedMessages001.h"

// stream launcher
#include "ISteamStreamLauncher001.h"

// controller
#include "ISteamController001.h"

// music
#include "ISteamMusic001.h"

// ugc
#include "ISteamUGC001.h"
#include "ISteamUGC002.h"

#ifndef NO_ICLIENT
// client interfaces
#include "IClientEngine.h"

#include "IClientAppManager.h"
#include "IClientApps.h"
#include "IClientAudio.h"
#include "IClientBilling.h"
#include "IClientContentServer.h"
#include "IClientDepotBuilder.h"
#include "IClientFriends.h"
#include "IClientGameCoordinator.h"
#include "IClientGameServer.h"
#include "IClientGameServerStats.h"
#include "IClientGameStats.h"
#include "IClientMasterServerUpdater.h"
#include "IClientMatchmaking.h"
#include "IClientMatchmakingServers.h"
#include "IClientNetworking.h"
#include "IClientRemoteStorage.h"
#include "IClientScreenshots.h"
#include "IClientUser.h"
#include "IClientUserStats.h"
#include "IClientUtils.h"
#include "IClientHTTP.h"
#include "IClientConfigStore.h"
#include "IClientUnifiedMessages.h"
#include "IClientStreamLauncher.h"
#include "IClientNetworkDeviceManager.h"
#include "IClientDeviceAuth.h"
#include "IClientMusic.h"
#include "IClientProductBuilder.h"
#include "IClientShortcuts.h"
#include "IClientStreamClient.h"
#include "IClientUGC.h"
#endif // NO_ICLIENT

// steam_api
#ifdef VERSION_SAFE_STEAM_API_INTERFACES
#include "CSteamAPIContext.h"
#endif // VERSION_SAFE_STEAM_API_INTERFACES

#if defined(__GNUC__) && defined(_WIN32)
#pragma pop_macro("virtual")
#endif