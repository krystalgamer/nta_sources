#include "..\..\StdInc.h"
HServerListRequest SteamMatchmakingServers002::RequestInternetServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}
HServerListRequest SteamMatchmakingServers002::RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::RequestLANServerList(iApp, pRequestServersResponse);
}
HServerListRequest SteamMatchmakingServers002::RequestFriendsServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}
HServerListRequest SteamMatchmakingServers002::RequestFavoritesServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}
HServerListRequest SteamMatchmakingServers002::RequestHistoryServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}
HServerListRequest SteamMatchmakingServers002::RequestSpectatorServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
}

void SteamMatchmakingServers002::ReleaseRequest( HServerListRequest hServerListRequest )
{
    ProxiedMatchmakingServers::ReleaseRequest(hServerListRequest);
}

gameserveritem_t *SteamMatchmakingServers002::GetServerDetails( HServerListRequest hRequest, int iServer )
{
    return ProxiedMatchmakingServers::GetServerDetails(hRequest, iServer);
}

void SteamMatchmakingServers002::CancelQuery( HServerListRequest hRequest )
{
    ProxiedMatchmakingServers::CancelQuery(hRequest);
}

void SteamMatchmakingServers002::RefreshQuery( HServerListRequest hRequest )
{
    ProxiedMatchmakingServers::RefreshQuery(hRequest);
}

bool SteamMatchmakingServers002::IsRefreshing( HServerListRequest hRequest )
{
    return ProxiedMatchmakingServers::IsRefreshing(hRequest);
}

int SteamMatchmakingServers002::GetServerCount( HServerListRequest hRequest )
{
    return ProxiedMatchmakingServers::GetServerCount(hRequest);
}

void SteamMatchmakingServers002::RefreshServer( HServerListRequest hRequest, int iServer )
{
    ProxiedMatchmakingServers::RefreshServer(hRequest, iServer);
}

HServerQuery SteamMatchmakingServers002::PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::PingServer(unIP, usPort, pRequestServersResponse);
}

HServerQuery SteamMatchmakingServers002::PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::PlayerDetails(unIP, usPort, pRequestServersResponse);
}

HServerQuery SteamMatchmakingServers002::ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse )
{
    return ProxiedMatchmakingServers::ServerRules(unIP, usPort, pRequestServersResponse);
}

void SteamMatchmakingServers002::CancelServerQuery( HServerQuery hServerQuery )
{
    ProxiedMatchmakingServers::CancelServerQuery(hServerQuery);
}