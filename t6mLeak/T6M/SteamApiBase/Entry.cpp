#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "STDInc.h"
//#include <ws2tcpip.h>// we need this?

SOCKET dw_Entry::dwSocket = -1;
ULONG dw_Entry::masterAddr;
unsigned int dw_Entry::oneAtATimeHash(char *key)
{
	unsigned int hash, i;
	size_t len = strlen(key);
	for (hash = i = 0; i < len; ++i)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}
hostent* WINAPI dw_Entry::custom_gethostbyname(const char* name)
{
	Log::Debug("custom_gethostbyname", name);
	unsigned int ip1 = oneAtATimeHash("ops2-pc-auth.prod.demonware.net");
	unsigned int log1 = oneAtATimeHash("ops2-pc-lobby.prod.demonware.net");
	unsigned int log2 = oneAtATimeHash("cod7-stun.us.demonware.net");
	unsigned int log3 = oneAtATimeHash("cod7-stun.eu.demonware.net");
	unsigned int log4 = oneAtATimeHash("cod7-stun.jp.demonware.net");
	unsigned int log5 = oneAtATimeHash("cod7-stun.au.demonware.net");


	unsigned int current = oneAtATimeHash((char*)name);
	char* hostname = (char*)name;

	if (current == log1 || current == ip1)
	{
		hostname = MASTER_SERVER;
	}
	return gethostbyname(hostname);
}
int WINAPI dw_Entry::dw_connect(SOCKET socket, const sockaddr* name, int namelen)
{
	if (!masterAddr)
	{
		hostent* host = gethostbyname(MASTER_SERVER);
		if (host)
		{
			masterAddr = *(ULONG*)host->h_addr_list[0];
		}
		else
		{
			masterAddr = -1;
		}
	}
	if (namelen == sizeof(sockaddr_in))
	{
		sockaddr_in* addr = (sockaddr_in*)name;
		if (addr->sin_addr.S_un.S_addr == masterAddr && addr->sin_port == htons(3074))
		{
			dw_Entry::dwSocket = socket;
			return 0;
		}
	}
	return connect(socket, name, namelen);
}
int WINAPI dw_Entry::dw_send(SOCKET socket, const char* buf, int len, int flags)
{
	if (socket == dw_Entry::dwSocket)
	{
		dw_Handler::dw_handle_packet(buf, len);
		return len;
	}
	return send(socket, buf, len, flags);
}
int WINAPI dw_Entry::dw_sendto(SOCKET socket, const char* buf, int len, int flags, const sockaddr* to, int tolen)
{
	if (socket == dw_Entry::dwSocket)
	{
		dw_Handler::dw_handle_packet(buf, len);
		return len;
	}
	return sendto(socket, buf, len, flags, to, tolen);
}
int WINAPI dw_Entry::dw_recv(SOCKET socket, char* buf, int len, int flags)
{
	if (socket != dw_Entry::dwSocket)
	{
		return recv(socket, buf, len, flags);
	}
	if (dw_Handler::dw_packet_available())
	{
		return dw_Handler::dw_dequeue_packet(buf, len);
	}
	WSASetLastError(WSAEWOULDBLOCK);
	return SOCKET_ERROR;
}
int WINAPI dw_Entry::dw_recvfrom(SOCKET socket, char* buf, int len, int flags, sockaddr* from, int* fromlen)
{
	if (socket != dw_Entry::dwSocket)
	{
		return recvfrom(socket, buf, len, flags, from, fromlen);
	}
	if (dw_Handler::dw_packet_available())
	{
		return dw_Handler::dw_dequeue_packet(buf, len);
	}
	WSASetLastError(WSAEWOULDBLOCK);
	return SOCKET_ERROR;
}
int	WINAPI dw_Entry::dw_select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, const timeval* timeout)
{
	bool containsDWSocket = false;
	bool containsDWSocketRead = false;
	if (writefds && (dw_Entry::dwSocket != -1))
	{
		if (FD_ISSET(dw_Entry::dwSocket, writefds))
		{
			containsDWSocket = true;
			Log::Debug("dwentry", "removed DW socket from select() call (write)\n");
		}
	}
	if (readfds && (dw_Entry::dwSocket == -1))
	{
		if (FD_ISSET(dw_Entry::dwSocket, readfds))
		{
			containsDWSocketRead = true;
			FD_CLR(dw_Entry::dwSocket, readfds);
			Log::Debug("dwentry", "removed DW socket from select() call (read)\n");
		}
	}
	if (exceptfds && (dw_Entry::dwSocket == -1))
	{
		if (FD_ISSET(dw_Entry::dwSocket, exceptfds))
		{
			FD_CLR(dw_Entry::dwSocket, exceptfds);
			Log::Debug("dwentry", "removed DW socket from select() call (except)\n");
		}
	}
	int retval = select(nfds, readfds, writefds, exceptfds, timeout);
	if (containsDWSocket)
	{
		FD_SET(dw_Entry::dwSocket, writefds);
		retval++;
	}
	if (containsDWSocketRead)
	{
		if (dw_Handler::dw_packet_available())
		{
			FD_SET(dw_Entry::dwSocket, readfds);
			retval++;
		}
	}
	return retval;
}