#include "STDInc.h"

Hook::Stomp DLC::_CheckFlag;
Hook::Stomp DLC::_OwnMap;



int DLC::DLCAppID(int DLC_Index)
{
	if (DLC_Index > 32)
	{
		if (DLC_Index > 4096)
		{
			if (DLC_Index == 0x8000)
				return 219095;
		}
		else
		{
			if (DLC_Index == 4096)
				return 219093;
			if (DLC_Index == 64)
				return 219101;
			if (DLC_Index == 128)
				return 219103;
		}
		return 0;
	}
	if (DLC_Index == 32)
		return 219098;
	if (DLC_Index == 2)
		return 202990;
	if (DLC_Index == 4)
		return 219091;
	if (DLC_Index == 8)
		return 219092;
	if (DLC_Index == 16)
		return 219097;
	return 0;
}
bool DLC::CheckFlag(int DLC_Index)
{
	bool result;
	bool ISMP = Global::Game::Type == GameType::GAME_TYPE_MP ? true : false;

	switch (DLC_Index)
	{
	case 2:
		result = 1;
		break;
	case 4:
		result = GetFileAttributesA("zone\\all\\mp_nuketown_2020.ff") != -1;
		break;
	case 8:
		result = GetFileAttributesA("zone\\all\\zm_nuked.ff") != -1;
		break;
	case 16:
		if (ISMP)
			result = GetFileAttributesA("zone\\all\\mp_downhill.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_hydro.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_mirage.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_skate.ff") != -1;
		else
			result = GetFileAttributesA("zone\\all\\zm_highrise.ff") != -1;
		break;
	case 32:
		if (ISMP)
			result = GetFileAttributesA("zone\\all\\mp_bridge.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_castaway.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_uplink.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_paintball.ff") != -1;
		else
			result = GetFileAttributesA("zone\\all\\zm_prison.ff") != -1;
		break;
	case 64:
		if (ISMP)
			result = GetFileAttributesA("zone\\all\\mp_bridge.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_castaway.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_uplink.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_paintball.ff") != -1;
		else
			result = GetFileAttributesA("zone\\all\\zm_buried.ff") != -1;
		break;
	case 128:
		if (ISMP)
			result = GetFileAttributesA("zone\\all\\mp_dig.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_frostbite.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_pod.ff") != -1
			&& GetFileAttributesA("zone\\all\\mp_takeoff.ff") != -1;
		else
			result = GetFileAttributesA("zone\\all\\zm_tomb.ff") != -1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}
void DLC::Initialize()
{
	if (Global::Game::Type == GameType::GAME_TYPE_MP)
	{
		// Hax for missing DLC
		*(BYTE*)Addresses::MissingDLC = 0xEB;

		// Check FastFiles
		DLC::_CheckFlag.Initialize(Addresses::CheckFlag, DLC::CheckFlag);
		DLC::_CheckFlag.InstallHook();

		// Do we have the DLC?
		DLC::_OwnMap.Initialize(Addresses::CheckFlag, DLC::DLCAppID);
		DLC::_OwnMap.InstallHook();
	}
}