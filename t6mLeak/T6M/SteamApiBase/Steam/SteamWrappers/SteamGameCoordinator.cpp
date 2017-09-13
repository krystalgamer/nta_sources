/*
	This project is released under the GPL 2.0 license.
	Please do no evil.

	Initial author: (https://github.com/)Convery
	Started: 2015-04-08
	Notes:
	Information about the game.
	*/
#include "..\..\StdInc.h"

#pragma region SteamGameCoordinator001
EGCResults SteamGameCoordinator001::SendMessage( uint32 unMsgType, const void *pubData, uint32 cubData )
{
	return EGCResults::k_EGCResultOK;
}
    
bool SteamGameCoordinator001::IsMessageAvailable( uint32 *pcubMsgSize )
{
	return false;
}

EGCResults SteamGameCoordinator001::RetrieveMessage( uint32 *punMsgType, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize )
{
	return EGCResults::k_EGCResultOK;
}
#pragma endregion