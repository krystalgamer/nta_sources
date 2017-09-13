#include "STDInc.h"
int scr_numParams = 0;
void NotificationSystem::Push(char* value)
{
	// Push string onto the script stack
	Addresses::Scr_AddString(0, value);
	scr_numParams++;
}
void NotificationSystem::Push(g_entity_s* value)
{
	// Push entity onto the script stack
	Addresses::Scr_AddEntity(0, value);
	scr_numParams++;
}
void NotificationSystem::Push(int value)
{
	// Push integer onto the script stack
	Addresses::Scr_AddInt(0, value);
	scr_numParams++;
}
void NotificationSystem::NotifyClient(int clientNum, char* notify)
{
	// Convert notify command into a string reference
	short s_notify = Addresses::SL_GetString(notify, 0);

	// Notify with pushed params for given client
	Addresses::Scr_NotifyNum(clientNum, 0, s_notify, scr_numParams);

	// Reset param count
	scr_numParams = 0;
}