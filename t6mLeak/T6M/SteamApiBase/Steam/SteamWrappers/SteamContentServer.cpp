#include "..\..\StdInc.h"
bool SteamContentServer002::LogOn( uint32 uContentServerID )
{
	return true;
}
bool SteamContentServer002::LogOff()
{
	return false;
}
bool SteamContentServer002::BLoggedOn()
{
	return true;
}
void SteamContentServer002::SendClientContentAuthRequest( CSteamID steamID, uint32 uContentID, uint64 ulSessionToken, bool bTokenPresent )
{

}
bool SteamContentServer002::BCheckTicket( CSteamID steamID, uint32 uContentID, const void *pvTicketData, uint32 cubTicketLength )
{
	return true;
}