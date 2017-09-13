#pragma once
class dw_Entry
{
public:
	static SOCKET dwSocket;
	static ULONG masterAddr;

	static unsigned int oneAtATimeHash(char *key);
	static hostent* WINAPI custom_gethostbyname(const char* name);
	static int WINAPI dw_connect(SOCKET socket, const sockaddr* name, int namelen);
	static int WINAPI dw_send(SOCKET socket, const char* buf, int len, int flags);
	static int WINAPI dw_sendto(SOCKET socket, const char* buf, int len, int flags, const sockaddr* to, int tolen);
	static int WINAPI dw_recv(SOCKET socket, char* buf, int len, int flags);
	static int WINAPI dw_recvfrom(SOCKET socket, char* buf, int len, int flags, sockaddr* from, int* fromlen);
	static int WINAPI dw_select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, const timeval* timeout);
};