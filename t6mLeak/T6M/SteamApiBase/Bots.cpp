#include "STDInc.h"

#define BOT_CLAN_TAG "Sonsored"
char* Bots::NameList[] =
{
	"^1m^2i^3c^4h^5i",
	"^1J^2ü^3r^5g^6e^7n Trovato",
	"Sonsored",
	"Sonsored",
	"Kenshin13",
	"Sonsored",
	"Sonsored",
	"Sonsored",
	"Convery",
	"NTAuthority",
	"embient_mp_highrise",
};
void Bots::SpawnBots(unsigned int amount)
{
	// Add desired amount of bots
	std::vector<g_entity_s*> entRefs;
	for (unsigned int i = 0; i < amount; i++)
	{
		Sleep(10);

		g_entity_s* entRef = Addresses::SV_AddTestClient();

		if (entRef)
		{
			entRefs.push_back(entRef);
		}
		else
		{
			break;
		}
	}
	// Wait 1 second for the bots to join the game
	Addresses::Cbuf_AddText(0, "wait 100;");
	for (int i = 0; i < entRefs.size(); i++)
	{
		// Change bot class
		Addresses::Cbuf_AddText(0, hString::va("autoChangeClass %d;", entRefs[i]->s.number));
	}
}
void Bots::spawnBot_f()
{
	int count = (Command::Cmd_ArgC() > 1 ? atoi(Command::Cmd_ArgV(1)) : 1);
	// Check if ingame and host
	if (Addresses::SV_Loaded())
	{
		if (!strcmp(Command::Cmd_ArgV(1), "all"))
		{
			SpawnBots(-1);
			Addresses::Com_Printf("Max. amount of bots spawned successfully!\n");
		}
		else
		{
			SpawnBots(count);
			Addresses::Com_Printf(hString::va("%d bots spawned successfully!\n", count));
		}
	}
	else
	{
		Addresses::Com_Printf("You need to be host to spawn bots!\n");
	}
}
void Bots::autoChangeClass_f()
{
	if (Command::Cmd_ArgC() != 2) return;
	int client = atoi(Command::Cmd_ArgV(1));
	NotificationSystem::Push("class_assault");
	NotificationSystem::Push("changeclass");
	NotificationSystem::NotifyClient(client, "menuresponse");
	if (Command::Cmd_ArgC() != 2)
		return;
}
void Bots::Initialize()
{
	// Replace staff array with custom one
	*(char***)Addresses::BotArray1 = Bots::NameList;
	*(char***)Addresses::BotArray2 = Bots::NameList;
	*(char***)Addresses::BotArray3 = Bots::NameList;

	// Apply new array size
	int size = (sizeof(Bots::NameList) / sizeof(Bots::NameList[0]));
	*(BYTE*)Addresses::BotArraySize1 = size;
	*(BYTE*)Addresses::BotArraySize2 = size;
	*(BYTE*)Addresses::BotArraySize3 = size;
	*(BYTE*)Addresses::BotArraySize4 = size;

	// Apply new clan tags
	*(char**)Addresses::BotTag1 = "connect \"\\invited\\1\\cg_predictItems\\1\\cl_anonymous\\0\\color\\4\\head\\default\\model\\multi\\snaps\\20\\rate\\5000\\name\\%s\\clanAbbrev\\" BOT_CLAN_TAG "\\xuid\\%s\\xnaddr\\%s\\natType\\2\\protocol\\%d\\netfieldchk\\%d\\sessionmode\\%d\\migrating\\1\"";
	*(char**)Addresses::BotTag2 = "connect \"\\invited\\1\\cg_predictItems\\1\\cl_anonymous\\0\\color\\4\\head\\default\\model\\multi\\snaps\\20\\rate\\5000\\name\\%s\\clanAbbrev\\" BOT_CLAN_TAG "\\xuid\\%s\\xnaddr\\%s\\natType\\2\\protocol\\%d\\netfieldchk\\%d\\sessionmode\\%d\\qport\\%d\"";

	// Add Commands to Spawn some bots
	static cmd_function_s spawnBot_cmd;
	Addresses::Cmd_AddCommandInternal("spawnBot", Bots::spawnBot_f, &spawnBot_cmd);
}