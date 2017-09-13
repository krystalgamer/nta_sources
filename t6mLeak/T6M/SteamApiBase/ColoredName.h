#pragma once
class ColoredName
{
public:
	static void Initialize();
private:
	static void ClientUserinfoChanged_Stub();
	static char* CL_GetClientName_Stub(LocalClientNum_t localClientNum, int index, char *buf, int _size, bool addClanName);
};