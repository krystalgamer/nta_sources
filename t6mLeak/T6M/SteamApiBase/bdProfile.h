#pragma once
class bdProfile
{
public:
	static void bdProfile::HandleMessage(int type, const char* buf, int len);
	static void bdProfile::SaveCallingCard(bdByteBuffer& data);
	static void bdProfile::DownloadCallingCardsofFriends(bdByteBuffer& data);
};