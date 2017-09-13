#pragma once
class DLC
{
private:
	static Hook::Stomp _CheckFlag;
	static Hook::Stomp _OwnMap;
	static bool CheckFlag(int DLC_Index);
	static int DLCAppID(int DLC_Index);
public:
	static void Initialize();
};