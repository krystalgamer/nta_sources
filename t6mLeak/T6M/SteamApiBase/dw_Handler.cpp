#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "STDInc.h"

#include <fstream>

bool					dw_Handler::queuedPacketHere = false;
std::queue<char>		dw_Handler::packetQueue;
CRITICAL_SECTION		dw_Handler::packetCS;
std::queue<std::string> dw_Handler::incomingQueue;
CRITICAL_SECTION		dw_Handler::incomingCS;

DWORD WINAPI dw_Handler::dw_thread(LPVOID param)
{
	while (true)
	{
		Sleep(1);
		if (dw_Handler::incomingQueue.empty())
		{
			continue;
		}
		EnterCriticalSection(&dw_Handler::incomingCS);
		std::string packet = dw_Handler::incomingQueue.front();
		dw_Handler::incomingQueue.pop();
		LeaveCriticalSection(&dw_Handler::incomingCS);
		const char* buf = packet.c_str();
		int buflen = packet.size();
		int pos = 0;
		while (pos < buflen)
		{
			int origin = 0;
			int totalBytes = *(int*)(buf + pos);
			if (totalBytes == 0xC8)
			{
				Log::Debug("dwhandler", "Got a C8 packet");
				char packet[15] = { 0x0B, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0a, 0x9D, 0x28, 0x25, 0xCD, 0x9B, 0xC9, 0x81, 0x64 };
				dw_Handler::dw_queue_packet(packet, sizeof(packet));
				break;
			}
			if (totalBytes <= 0)
			{
				Log::Debug("dwhandler", "send heartbeat message");
				char emptyPacket[4] = { 0, 0, 0, 0 };
				dw_Handler::dw_queue_packet(emptyPacket, sizeof(emptyPacket));
				break;
			}
			pos += 4;
			if (buf[pos] != 0xFF)
			{
				dw_Handler::dw_handle_message(buf + pos, totalBytes);
				pos += totalBytes;
			}
		}
	}
	return 0;
}
void dw_Handler::UnknownMessageInit(bdByteBuffer& data)
{

}
void dw_Handler::UnknownMessage(int type, const char* buf, int len)
{
	bdByteBuffer data((char*)buf, len);
	char subtype = 0;
	data.readByte(&subtype);
	Log::Debug("bdUnknown",hString::va("%d subtype", subtype));
	dw_Handler::UnknownMessageInit(data);
}
void dw_Handler::dw_handle_message(const char* buf, int len)
{
	char* bufpacket;
	const char* buf1 = buf;
	int len1 = len;
	BYTE ptype = 0xFF;
	bool encrypted = false;

	// encrypted?
	if (buf[0] == 1)
	{
		// yes
		encrypted = true;
		buf++;
		len--;

		// get IV seed
		unsigned int ivSeed = *(unsigned int*)buf;
		buf += 4;
		len -= 4;

		// calculate IV and decrypt
		BYTE iv[24];
		BYTE key[24];

		static char data[256 * 1024];
		dw_Crypto::dw_calculate_iv(ivSeed, iv);
		dw_Crypto::dw_get_global_key(key);
		dw_Crypto::dw_decrypt_data(buf, iv, key, data, len);

		buf = data;
		// skip 'hash'
		buf += 4;
		len -= 4;
	}
	else
	{
		buf++;
		len--;
	}
	// read packet type
	ptype = buf[0];
	buf++;
	len--;

	// Dispatch Packet to a Handler.
	dw_Handler::queuedPacketHere = false;



	Log::Error("DW stuff", "ptype = %i encrypted = %s", ptype, encrypted ? "true" : "false");


	if (encrypted)
	{
		if (ptype == 10)
		{
			Storage::dw_handle_storage_message(ptype, buf, len);
		}
		else if (ptype == 12 || ptype == 27 || ptype == 6)
		{
			TitleUtils::dw_handle_tutils_message(ptype, buf, len);
		}
		else if (ptype == 21)
		{
			dw_match::match_packet_received(ptype, buf, len);
		}
		else if (ptype == 8)
		{
			bdProfile::HandleMessage(ptype, buf, len);
			std::ofstream fp;
			fp.open(hString::va("encrypted %d", ptype), std::ios::out | std::ios::binary);
			fp.write((char*)buf, len);
		}
		else
		{
			std::ofstream fp;
			fp.open(hString::va("encrypted %d", ptype), std::ios::out | std::ios::binary);
			fp.write((char*)buf, len);
		}
		if (!queuedPacketHere)
		{
			dwMessage reply(1, false);
			reply.byteBuffer.writeUInt64(0x8000000000000001);
			//reply.byteBuffer.writeUInt32(2);
			reply.byteBuffer.writeUInt32(0);
			reply.byteBuffer.writeUInt32(0);
			reply.byteBuffer.writeUInt32(0);
			reply.send(true);
		}
	}
	else
	{
		if (ptype == 28 || ptype == 12 || ptype == 26)
		{
			dw_Auth::dw_handle_auth_message(ptype, buf, len);
		}
		else if (ptype == 7)
		{
			dw_Auth::dw_handle_lobby_message(ptype, buf, len);
		}
		else
		{
			std::ofstream fp;
			fp.open(hString::va("not encrypted %d", ptype), std::ios::out | std::ios::binary);
			fp.write((char*)buf, len);
		}
	}
}
void dw_Handler::dw_queue_packet(char* buf, int len)
{
	EnterCriticalSection(&dw_Handler::packetCS);
	for (int i = 0; i < len; i++)
	{
		dw_Handler::packetQueue.push(buf[i]);
	}
	LeaveCriticalSection(&dw_Handler::packetCS);
	dw_Handler::queuedPacketHere = true;
}
int dw_Handler::dw_dequeue_packet(char* buf, int len)
{
	if (!dw_Handler::packetQueue.empty())
	{
		EnterCriticalSection(&dw_Handler::packetCS);
		int toPop = min(dw_Handler::packetQueue.size(), len);
		for (int i = 0; i < toPop; i++)
		{
			buf[i] = dw_Handler::packetQueue.front();
			dw_Handler::packetQueue.pop();
		}
		LeaveCriticalSection(&dw_Handler::packetCS);
		return toPop;
	}
	return 0;
}
bool dw_Handler::dw_packet_available()
{
	return !dw_Handler::packetQueue.empty();
}
void dw_Handler::dw_im_received(PMID from, const uint8_t* buf, uint32_t buflen)
{
	Log::Debug("dwhandler", "received IM from %llx", from);
	dwMessage msg(2, false);
	msg.byteBuffer.writeUInt32(21);
	msg.byteBuffer.writeUInt64(from);
	msg.byteBuffer.writeString("me");
	msg.byteBuffer.writeBlob((const char*)buf, buflen);
	msg.send(true);
}
void dw_Handler::dw_handle_packet(const char* buf, int buflen)
{
	EnterCriticalSection(&dw_Handler::incomingCS);
	std::string packet(buf, buflen);
	dw_Handler::incomingQueue.push(packet);
	LeaveCriticalSection(&dw_Handler::incomingCS);
}
void dw_Handler::dw_build_lsg_ticket(char* buf, char* key)
{
	memset(buf, 0, 128);
	memcpy(buf, key, 24);
}
void dw_Handler::dw_build_game_ticket(char* buf, char* key, int gameID)
{
	dw_game_ticket* ticket = (dw_game_ticket*)buf;
	memset(ticket, 0xA, sizeof(dw_game_ticket));
	ticket->signature[0] = 0xDE;
	ticket->signature[1] = 0xAD;
	ticket->signature[2] = 0xBD;
	ticket->signature[3] = 0xEF;
	ticket->licenseType = 0;
	ticket->gameID = gameID;
	ticket->userID = 0x1100001DEADC0DE;
	ticket->nick[0] = 'a';
	ticket->nick[1] = 0;
	memcpy(ticket->key, key, sizeof(ticket->key));
}