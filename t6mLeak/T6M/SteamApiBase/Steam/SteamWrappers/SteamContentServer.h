#pragma once
class SteamContentServer002 : public ISteamContentServer002
{
public:
    bool LogOn( uint32 uContentServerID );
    bool LogOff(); 
    bool BLoggedOn();
    void SendClientContentAuthRequest( CSteamID steamID, uint32 uContentID, uint64 ulSessionToken, bool bTokenPresent );
    bool BCheckTicket( CSteamID steamID, uint32 uContentID, const void *pvTicketData, uint32 cubTicketLength );
};