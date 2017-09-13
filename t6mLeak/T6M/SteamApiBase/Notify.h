#pragma once
class NotificationSystem
{
public:
	static void Push(char* value);
	static void Push(g_entity_s* value);
	static void Push(int value);
	static void NotifyClient(int clientNum, char* notify);
};