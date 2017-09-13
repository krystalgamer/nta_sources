#include "..\..\StdInc.h"
#pragma once
bool SteamNetworking005::SendP2PPacket(CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType, int iPort)
{
	return ProxiedNetworking::SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, iPort);
}

bool SteamNetworking005::IsP2PPacketAvailable(uint32 *pcubMsgSize, int iPort)
{
	return ProxiedNetworking::IsP2PPacketAvailable(pcubMsgSize, iPort);
}

bool SteamNetworking005::ReadP2PPacket(void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote, int iPort)
{
	return ProxiedNetworking::ReadP2PPacket(pubDest, cubDest, pcubMsgSize, psteamIDRemote, iPort);
}

bool SteamNetworking005::AcceptP2PSessionWithUser(CSteamID steamIDRemote)
{
	return ProxiedNetworking::AcceptP2PSessionWithUser(steamIDRemote);
}

bool SteamNetworking005::CloseP2PSessionWithUser(CSteamID steamIDRemote)
{
	return ProxiedNetworking::CloseP2PSessionWithUser(steamIDRemote);
}

bool SteamNetworking005::CloseP2PChannelWithUser(CSteamID steamIDRemote, int iPort)
{
	return ProxiedNetworking::CloseP2PChannelWithUser(steamIDRemote, iPort);
}

bool SteamNetworking005::GetP2PSessionState(CSteamID steamIDRemote, P2PSessionState_t *pConnectionState)
{
	return ProxiedNetworking::GetP2PSessionState(steamIDRemote, pConnectionState);
}

bool SteamNetworking005::AllowP2PPacketRelay(bool bAllow)
{
	return ProxiedNetworking::AllowP2PPacketRelay(bAllow);
}

SNetListenSocket_t SteamNetworking005::CreateListenSocket(int nP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay)
{
	return ProxiedNetworking::CreateListenSocket(nP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
}

SNetSocket_t SteamNetworking005::CreateP2PConnectionSocket(CSteamID steamIDTarget, int nPort, int nTimeoutSec, bool bAllowUseOfPacketRelay)
{
	return ProxiedNetworking::CreateP2PConnectionSocket(steamIDTarget, nPort, nTimeoutSec, bAllowUseOfPacketRelay);
}
SNetSocket_t SteamNetworking005::CreateConnectionSocket(uint32 nIP, uint16 nPort, int nTimeoutSec)
{
	return ProxiedNetworking::CreateConnectionSocket(nIP, nPort, nTimeoutSec);
}

bool SteamNetworking005::DestroySocket(SNetSocket_t hSocket, bool bNotifyRemoteEnd)
{
	return ProxiedNetworking::DestroySocket(hSocket, bNotifyRemoteEnd);
}

bool SteamNetworking005::DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemoteEnd)
{
	return ProxiedNetworking::DestroyListenSocket(hSocket, bNotifyRemoteEnd);
}


bool SteamNetworking005::SendDataOnSocket(SNetSocket_t hSocket, void *pubData, uint32 cubData, bool bReliable)
{
	return ProxiedNetworking::SendDataOnSocket(hSocket, pubData, cubData, bReliable);
}

bool SteamNetworking005::IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32 *pcubMsgSize)
{
	return ProxiedNetworking::IsDataAvailableOnSocket(hSocket, pcubMsgSize);
}

bool SteamNetworking005::RetrieveDataFromSocket(SNetSocket_t hSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize)
{
	return ProxiedNetworking::RetrieveDataFromSocket(hSocket, pubDest, cubDest, pcubMsgSize);
}

bool SteamNetworking005::IsDataAvailable(SNetListenSocket_t hListenSocket, uint32 *pcubMsgSize, SNetSocket_t *phSocket)
{
	return ProxiedNetworking::IsDataAvailable(hListenSocket, pcubMsgSize, phSocket);
}

bool SteamNetworking005::RetrieveData(SNetListenSocket_t hListenSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, SNetSocket_t *phSocket)
{
	return ProxiedNetworking::RetrieveData(hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
}

bool SteamNetworking005::GetSocketInfo(SNetSocket_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, uint32 *punIPRemote, uint16 *punPortRemote)
{
	return ProxiedNetworking::GetSocketInfo(hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
}

bool SteamNetworking005::GetListenSocketInfo(SNetListenSocket_t hListenSocket, uint32 *pnIP, uint16 *pnPort)
{
	return ProxiedNetworking::GetListenSocketInfo(hListenSocket, pnIP, pnPort);
}

ESNetSocketConnectionType SteamNetworking005::GetSocketConnectionType(SNetSocket_t hSocket)
{
	return ProxiedNetworking::GetSocketConnectionType(hSocket);
}


int SteamNetworking005::GetMaxPacketSize(SNetSocket_t hSocket)
{
	return ProxiedNetworking::GetMaxPacketSize(hSocket);
}