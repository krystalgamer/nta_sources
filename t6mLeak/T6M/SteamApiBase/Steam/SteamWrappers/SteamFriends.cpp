#include "..\..\StdInc.h"
// returns the local players name - guaranteed to not be NULL.
// this is the same name as on the users community profile page
// this is stored in UTF-8 format
// like all the other interface functions that return a char *, it's important that this pointer is not saved
// off {} it will eventually be free'd or re-allocated
const char *SteamFriends013::GetPersonaName()
{
	return Global::Variables::Steam_Username;
}

// sets the player name, stores it on the server and publishes the changes to all friends who are online
SteamAPICall_t SteamFriends013::SetPersonaName(const char *pchPersonaName)
{
	return 0;
}

// gets the status of the current user
EPersonaState SteamFriends013::GetPersonalState()
{
	return EPersonaState::k_EPersonaStateOnline;
}

// friend iteration
// takes a set of k_EFriendFlags, and returns the number of users the client knows about who meet that criteria
// then GetFriendByIndex() can then be used to return the id's of each of those users
int32_t SteamFriends013::GetFriendCount(int32_t iFriendFlags)
{
	return xNP_GetTotalFriends();
}

// returns the steamID of a user
// iFriend is a index of range [0, GetFriendCount())
// iFriendsFlags must be the same value as used in GetFriendCount()
// the returned CSteamID can then be used by all the functions below to access details about the user
CSteamID SteamFriends013::GetFriendByIndex(int32_t iFriend, int32_t iFriendFlags)
{
	return xNP_GetFriendGUID(iFriend);
}

// returns a relationship to a user
EFriendRelationship SteamFriends013::GetFriendRelationship(CSteamID steamIDFriend)
{
	if (xNP_GetFriendlyName(steamIDFriend.ConvertToUint64()) != NULL)
	{
		return k_EFriendRelationshipFriend;
	}

	return k_EFriendRelationshipNone;
}

// returns the current status of the specified user
// this will only be known by the local user if steamIDFriend is in their friends list {} on the same game server {} in a chat room or lobby {} or in a small group with the local user
EPersonaState SteamFriends013::GetFriendPersonaState(CSteamID steamIDFriend) 
{
	switch (xNP_GetFriendPresence(steamIDFriend.ConvertToUint64()))
	{
	case PresenceStateOnline:
		return k_EPersonaStateOnline;
	case PresenceStateAway:
		return k_EPersonaStateAway;
	case PresenceStateExtendedAway:
		return k_EPersonaStateSnooze;
	}

	return k_EPersonaStateOffline;
}

// returns the name another user - guaranteed to not be NULL.
// same rules as GetFriendPersonaState() apply as to whether or not the user knowns the name of the other user
// note that on first joining a lobby, chat room or game server the local user will not known the name of the other users automatically {} that information will arrive asyncronously
// 
const char *SteamFriends013::GetFriendPersonaName(CSteamID steamIDFriend) 
{
	return xNP_GetFriendlyName(steamIDFriend.ConvertToUint64());
}

// returns true if the friend is actually in a game, and fills in pFriendGameInfo with an extra details 
bool SteamFriends013::GetFriendGamePlayed(CSteamID steamIDFriend, FriendGameInfo_t *pFriendGameInfo)
{
	const char* friendGame = xNP_GetFriendRichPresence(steamIDFriend.ConvertToUint64(), "currentGame");

	if (friendGame == "t6mp")
	{
		pFriendGameInfo->m_gameID = CGameID(202990);//ZM 212910
	}
	else if (friendGame == "t6zm")
	{
		pFriendGameInfo->m_gameID = CGameID(212910);//ZM 212910
	}
	else
	{

	}

	//TODO : impelent player's gameinfo to be listed on friends list

	return true;
}

// Rich Presence data is automatically shared between friends who are in the same game
// Each user has a set of Key/Value pairs
// Up to 20 different keys can be set
// There are two magic keys:
//		"status"  - a UTF-8 string that will show up in the 'view game info' dialog in the Steam friends list
//		"connect" - a UTF-8 string that contains the command-line for how a friend can connect to a game
// GetFriendRichPresence() returns an empty string "" if no value is set
// SetRichPresence() to a NULL or an empty string deletes the key
// You can iterate the current set of keys for a friend with GetFriendRichPresenceKeyCount()
// and GetFriendRichPresenceKeyByIndex() (typically only used for debugging)
bool SteamFriends013::SetRichPresence(const char *pchKey, const char *pchValue)
{
	HHSDBG();
	Log::Debug("SteamFriends", "%s for value %s", pchKey, pchValue);
	xNP_SetRichPresence(pchKey, pchValue);
	xNP_StoreRichPresence();
	return true;
}
void SteamFriends013::ClearRichPresence()
{
	HHSDBG();
	xNP_SetRichPresence("", "");
	xNP_SetRichPresenceBody("");
	xNP_StoreRichPresence();
}
const char *SteamFriends013::GetFriendRichPresence(CSteamID steamIDFriend, const char *pchKey)
{
	Log::Debug("SteamFriends013::GetFriendRichPresence", pchKey);
	return xNP_GetFriendRichPresence(steamIDFriend.ConvertToUint64(), pchKey);
}
int32_t SteamFriends013::GetFriendRichPresenceKeyCount(CSteamID steamIDFriend)
{
	HHSDBG();
	return 0;
}
const char *SteamFriends013::GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int32_t iKey)
{
	HHSDBG();
	return "";
}
void SteamFriends013::RequestFriendRichPresence(CSteamID steamIDFriend)
{
	HHSDBG();
}


// accesses old friends names - returns an empty string when their are no more items in the history
const char *SteamFriends013::GetFriendPersonaNameHistory(CSteamID steamIDFriend, int32_t iPersonaName) 
{
	return "";
}

// returns true if the specified user meets any of the criteria specified in iFriendFlags
// iFriendFlags can be the union (binary or, |) of one or more k_EFriendFlags values
bool SteamFriends013::HasFriend(CSteamID steamIDFriend, int32_t iFriendFlags) 
{
	return NULL;
}

// clan (group) iteration and access functions
int32_t SteamFriends013::GetClanCount() 
{
	return NULL;
}
CSteamID SteamFriends013::GetClanByIndex(int32_t iClan) 
{
	return CSteamID();
}
const char *SteamFriends013::GetClanName(CSteamID steamIDClan) 
{
	return "Sonsored";
}
const char *SteamFriends013::GetClanTag(CSteamID steamIDClan) 
{
	return "Sonsored";
}

bool SteamFriends013::GetClanActivityCounts(CSteamID steamID, int32_t *pnOnline, int32_t *pnInGame, int32_t *pnChatting) 
{
	return NULL;
}
SteamAPICall_t SteamFriends013::DownloadClanActivityCounts(CSteamID groupIDs[], int32_t nIds) 
{
	return NULL;
}

// iterators for getting users in a chat room, lobby, game server or clan
// note that large clans that cannot be iterated by the local user
// steamIDSource can be the steamID of a group, game server, lobby or chat room
int32_t SteamFriends013::GetFriendCountFromSource(CSteamID steamIDSource) 
{
	return NULL;
}
CSteamID SteamFriends013::GetFriendFromSourceByIndex(CSteamID steamIDSource, int32_t iFriend) 
{
	return CSteamID();
}

// returns true if the local user can see that steamIDUser is a member or in steamIDSource
bool SteamFriends013::IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource) 
{
	return NULL;
}

// User is in a game pressing the talk button (will suppress the microphone for all voice comms from the Steam friends UI)
void SteamFriends013::SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking) 
{

}

// activates the game overlay, with an optional dialog to open 
// valid options are "Friends", "Community", "Players", "Settings", "LobbyInvite", "OfficialGameGroup", "Stats", "Achievements"
void SteamFriends013::ActivateGameOverlay(const char *pchDialog) 
{

}

// activates game overlay to a specific place
// valid options are
//		"steamid" - opens the overlay web browser to the specified user or groups profile
//		"chat" - opens a chat window to the specified user, or joins the group chat 
//		"stats" - opens the overlay web browser to the specified user's stats
//		"achievements" - opens the overlay web browser to the specified user's achievements
void SteamFriends013::ActivateGameOverlayToUser(const char *pchDialog, CSteamID steamID) 
{

}

// activates game overlay web browser directly to the specified URL
// full address with protocol type is required, e.g. http://www.steamgames.com/
void SteamFriends013::ActivateGameOverlayToWebPage(const char *pchURL) 
{

}

// activates game overlay to store page for app
void SteamFriends013::ActivateGameOverlayToStore(AppId_t nAppID, EOverlayToStoreFlag eFlag) 
{

}

// Mark a target user as 'played with'. This is a client-side only feature that requires that the calling user is 
// in game 
void SteamFriends013::SetPlayedWith(CSteamID steamIDUserPlayedWith) 
{

}

// activates game overlay to open the invite dialog. Invitations will be sent for the provided lobby.
// You can also use ActivateGameOverlay( "LobbyInvite" ) to allow the user to create invitations for their current public lobby.
void SteamFriends013::ActivateGameOverlayInviteDialog(CSteamID steamIDLobby) 
{

}

// gets the small (32x32) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
int32_t SteamFriends013::GetSmallFriendAvatar(CSteamID steamIDFriend) 
{
	return NULL;
}

// gets the medium (64x64) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
int32_t SteamFriends013::GetMediumFriendAvatar(CSteamID steamIDFriend) 
{
	return NULL;
}

// gets the large (184x184) avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
// returns -1 if this image has yet to be loaded, in this case wait for a AvatarImageLoaded_t callback and then call this again
int32_t SteamFriends013::GetLargeFriendAvatar(CSteamID steamIDFriend) 
{
	return NULL;
}

// requests information about a user - persona name & avatar
// if bRequireNameOnly is set, then the avatar of a user isn't downloaded 
// - it's a lot slower to download avatars and churns the local cache, so if you don't need avatars, don't request them
// if returns true, it means that data is being requested, and a PersonaStateChanged_t callback will be posted when it's retrieved
// if returns false, it means that we already have all the details about that user, and functions can be called immediately
bool SteamFriends013::RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly) 
{
	return NULL;
}

// requests information about a clan officer list
// when complete, data is returned in ClanOfficerListResponse_t call result
// this makes available the calls below
// you can only ask about clans that a user is a member of
// note that this won't download avatars automatically {} if you get an officer,
// and no avatar image is available, call RequestUserInformation( steamID, false ) to download the avatar
SteamAPICall_t SteamFriends013::RequestClanOfficerList(CSteamID steamIDClan) 
{
	return NULL;
}

// iteration of clan officers - can only be done when a RequestClanOfficerList() call has completed

// returns the steamID of the clan owner
CSteamID SteamFriends013::GetClanOwner(CSteamID steamIDClan) 
{
	return CSteamID();
}
// returns the number of officers in a clan (including the owner)
int32_t SteamFriends013::GetClanOfficerCount(CSteamID steamIDClan) 
{
	return NULL;
}
// returns the steamID of a clan officer, by index, of range [0,GetClanOfficerCount)
CSteamID SteamFriends013::GetClanOfficerByIndex(CSteamID steamIDClan, int32_t iOfficer) 
{
	return CSteamID();
}
// if current user is chat restricted, he can't send or receive any text/voice chat messages.
// the user can't see custom avatars. But the user can be online and send/recv game invites.
// a chat restricted user can't add friends or join any groups.
EUserRestriction SteamFriends013::GetUserRestrictions() 
{
	return k_nUserRestrictionNone;
}


// rich invite support
// if the target accepts the invite, the pchConnectString gets added to the command-line for launching the game
// if the game is already running, a GameRichPresenceJoinRequested_t callback is posted containing the connect string
// invites can only be sent to friends
bool SteamFriends013::InviteUserToGame(CSteamID steamIDFriend, const char *pchConnectString) 
{
	return true;
}

// recently-played-with friends iteration
// this iterates the entire list of users recently played with, across games
// GetFriendCoplayTime() returns as a unix time
int32_t SteamFriends013::GetCoplayFriendCount() 
{
	return 0;
}
CSteamID SteamFriends013::GetCoplayFriend(int32_t iCoplayFriend) 
{
	return CSteamID();
}
int32_t SteamFriends013::GetFriendCoplayTime(CSteamID steamIDFriend) 
{
	return 0;
}
AppId_t SteamFriends013::GetFriendCoplayGame(CSteamID steamIDFriend) 
{
	return 0;
}

// chat interface for games
// this allows in-game access to group (clan) chats from in the game
// the behavior is somewhat sophisticated, because the user may or may not be already in the group chat from outside the game or in the overlay
// use ActivateGameOverlayToUser( "chat", steamIDClan ) to open the in-game overlay version of the chat
SteamAPICall_t SteamFriends013::JoinClanChatRoom(CSteamID steamIDClan) 
{
	return 0;
}
bool SteamFriends013::LeaveClanChatRoom(CSteamID steamIDClan)
{
	return 0;
}
int32_t SteamFriends013::GetClanChatMemberCount(CSteamID steamIDClan) 
{
	return 0;
}
CSteamID SteamFriends013::GetChatMemberByIndex(CSteamID steamIDClan, int32_t iUser) 
{
	return CSteamID();
}
bool SteamFriends013::SendClanChatMessage(CSteamID steamIDClanChat, const char *pchText) 
{
	return 0;
}
int32_t SteamFriends013::GetClanChatMessage(CSteamID steamIDClanChat, int32_t iMessage, void *prgchText, int32_t cchTextMax, EChatEntryType *peChatEntryType, CSteamID *pSteamIDChatter) 
{
	return 0;
}
bool SteamFriends013::IsClanChatAdmin(CSteamID steamIDClanChat, CSteamID steamIDUser) 
{
	return 0;
}

// interact with the Steam (game overlay / desktop)
bool SteamFriends013::IsClanChatWindowOpenInSteam(CSteamID steamIDClanChat) 
{
	return 0;
}
bool SteamFriends013::OpenClanChatWindowInSteam(CSteamID steamIDClanChat) 
{
	return 0;
}
bool SteamFriends013::CloseClanChatWindowInSteam(CSteamID steamIDClanChat) 
{
	return 0;
}

// peer-to-peer chat interception
// this is so you can show P2P chats inline in the game
bool SteamFriends013::SetListenForFriendsMessages(bool bInterceptEnabled) 
{
	return 0;
}
bool SteamFriends013::ReplyToFriendMessage(CSteamID steamIDFriend, const char *pchMsgToSend) 
{
	return 0;
}
int32_t SteamFriends013::GetFriendMessage(CSteamID steamIDFriend, int32_t iMessageID, void *pvData, int32_t cubData, EChatEntryType *peChatEntryType) 
{
	return 0;
}

// following apis
SteamAPICall_t SteamFriends013::GetFollowerCount(CSteamID steamID) 
{
	return 0;
}
SteamAPICall_t SteamFriends013::IsFollowing(CSteamID steamID) 
{
	return 0;
}
SteamAPICall_t SteamFriends013::EnumerateFollowingList(uint32 unStartIndex) 
{
	return 0;
}