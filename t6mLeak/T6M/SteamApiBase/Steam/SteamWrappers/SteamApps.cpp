#include "..\..\StdInc.h"
bool SteamApps005::BIsSubscribed()
{
	return true;
}
bool SteamApps005::BIsLowViolence()
{
	return false;
}
bool SteamApps005::BIsCybercafe()
{
	return false;
}
bool SteamApps005::BIsVACBanned()
{
	return false;// add server Request
}
// Why is that function not called up?
const char *SteamApps005::GetCurrentGameLanguage()
{
	return Global::Variables::Steam_Language;
}
// Why is that function not called up?
const char *SteamApps005::GetAvailableGameLanguages()
{
	return Global::Variables::Steam_Language;
}
// only use this member if you need to check ownership of another game related to yours, a demo for example
bool SteamApps005::BIsSubscribedApp(AppId_t nAppID)
{
	return true;
}
// Takes AppID of DLC and checks if the user owns the DLC & if the DLC is installed
bool SteamApps005::BIsDlcInstalled(AppId_t nAppID)
{
	AppId_t DLCID = nAppID;
	if (DLCID == 219095)//season pass :P
	{
		return true;
	}
	else if (DLCID != 219092 || GetFileAttributesA("zone\\all\\zm_nuked.ff") == -1)
	{
		if (DLCID != 219091 || GetFileAttributesA("zone\\all\\mp_nuketown_2020.ff") == -1)
		{
			if (DLCID != 219097
				|| GetFileAttributesA("zone\\all\\mp_downhill.ff") == -1
				|| GetFileAttributesA("zone\\all\\mp_hydro.ff") == -1
				|| GetFileAttributesA("zone\\all\\mp_mirage.ff") == -1
				|| GetFileAttributesA("zone\\all\\mp_skate.ff") == -1)
			{
				if (DLCID != 219096 || GetFileAttributesA("zone\\all\\zm_highrise.ff") == -1)
				{
					if (DLCID != 219098
						|| GetFileAttributesA("zone\\all\\mp_magma.ff") == -1
						|| GetFileAttributesA("zone\\all\\mp_nightclub.ff") == -1
						|| GetFileAttributesA("zone\\all\\mp_studio.ff") == -1
						|| GetFileAttributesA("zone\\all\\mp_vertigo.ff") == -1)
					{
						if (DLCID != 219099 || GetFileAttributesA("zone\\all\\zm_prison.ff") == -1)
						{
							if (DLCID != 219101
								|| GetFileAttributesA("zone\\all\\mp_bridge.ff") == -1
								|| GetFileAttributesA("zone\\all\\mp_castaway.ff") == -1
								|| GetFileAttributesA("zone\\all\\mp_uplink.ff") == -1
								|| GetFileAttributesA("zone\\all\\mp_paintball.ff") == -1)
							{
								if (DLCID != 219102 || GetFileAttributesA("zone\\all\\zm_buried.ff") == -1)
								{
									if (DLCID != 219103
										|| GetFileAttributesA("zone\\all\\mp_dig.ff") == -1
										|| GetFileAttributesA("zone\\all\\mp_frostbite.ff") == -1
										|| GetFileAttributesA("zone\\all\\mp_pod.ff") == -1
										|| GetFileAttributesA("zone\\all\\mp_takeoff.ff") == -1)
									{
										if (DLCID != 219104 || GetFileAttributesA("zone\\all\\zm_tomb.ff") == -1)
										{
											return false;
										}
										else
										{
											return true;
										}
									}
									else
									{
										return true;
									}
								}
								else
								{
									return true;
								}
							}
							else
							{
								return true;
							}
						}
						else
						{
							return true;
						}
					}
					else
					{
						return true;
					}
				}
				else
				{
					return true;
				}
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}
// returns the Unix time of the purchase of the app
uint32 SteamApps005::GetEarliestPurchaseUnixTime(AppId_t nAppID)
{
	return 0;
}
// Checks if the user is subscribed to the current app through a free weekend
// This function will return false for users who have a retail or other type of license
// Before using, please ask your Valve technical contact how to package and secure your free weekened
bool SteamApps005::BIsSubscribedFromFreeWeekend()
{
	return false;
}
// Returns the number of DLC pieces for the running app
int SteamApps005::GetDLCCount()
{
	return 0;
}
// Returns metadata for DLC by index, of range [0, GetDLCCount()]
bool SteamApps005::BGetDLCDataByIndex(int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize)
{
	return false;
}
// Install/Uninstall control for optional DLC
void SteamApps005::InstallDLC(AppId_t nAppID)
{

}
void SteamApps005::UninstallDLC(AppId_t nAppID)
{

}
// Request cd-key for yourself or owned DLC. If you are interested in this
// data then make sure you provide us with a list of valid keys to be distributed
// to users when they purchase the game, before the game ships.
// You'll receive an AppProofOfPurchaseKeyResponse_t callback when
// the key is available (which may be immediately).
void SteamApps005::RequestAppProofOfPurchaseKey(AppId_t nAppID)
{

}

bool SteamApps005::GetCurrentBetaName(char *pchName, int cchNameBufferSize)
{
	pchName = "public";
	cchNameBufferSize = 7;
	return true;
}
bool SteamApps005::MarkContentCorrupt(bool bMissingFilesOnly)
{
	return false;
}
uint32 SteamApps005::GetInstalledDepots(DepotId_t *pvecDepots, uint32 cMaxDepots)
{
	return FALSE;
}

// returns current app install folder for AppID, returns folder name length
uint32 SteamApps005::GetAppInstallDir(AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize)
{
	return TRUE;
}
bool SteamApps005::BIsAppInstalled(AppId_t appID)
{
	return true;
}