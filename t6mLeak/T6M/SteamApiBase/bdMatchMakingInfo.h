#pragma once
#include "StdInc.h"
#include "dwMessage.h"
#include <stdio.h>

class bdMatchMakingInfo
{
public:
	bool Reachable;
	UINT32 InternalIPAddress;
	UINT16 InternalPort;
	char* Address;
	BYTE SessionID;
	unsigned int Unknown1;
	unsigned int Unknown2;
	UINT Players;
	int User;
	UINT32 IPAddress;
	UINT16 Port;
	bdMatchMakingInfo() {}
	void Deserialize(dwMessage packet);
	void Deserialize(bdByteBuffer packet);
	void Serialize(dwMessage packet);
	void Serialize(bdByteBuffer packet);
};