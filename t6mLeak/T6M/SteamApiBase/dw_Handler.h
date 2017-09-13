#pragma once
class dw_Handler
{
public:
	static bool queuedPacketHere;
	static std::queue<char> packetQueue;
	static CRITICAL_SECTION packetCS;
	static std::queue<std::string> incomingQueue;
	static CRITICAL_SECTION incomingCS;

	static DWORD WINAPI dw_thread(LPVOID param);
	static void dw_queue_packet(char* buf, int len);
	static int dw_dequeue_packet(char* buf, int len);
	static bool dw_packet_available();
	static void dw_im_received(PMID from, const uint8_t* buf, uint32_t buflen);
	static void dw_handle_message(const char* buf, int len);
	static void dw_handle_packet(const char* buf, int buflen);
	static void dw_build_game_ticket(char* buf, char* key, int gameID);
	static void dw_build_lsg_ticket(char* buf, char* key);
	static void UnknownMessageInit(bdByteBuffer& data);
	static void UnknownMessage(int type, const char* buf, int len);

};