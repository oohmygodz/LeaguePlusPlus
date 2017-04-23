#include "PluginSDK.h"

PluginSetup("oohmyChatSpammer")

IMenu* MainMenu;
IMenuOption* Enabled;

IMenu* Settings;
IMenuOption* Key;
IMenuOption* Key1;
IMenuOption* Key2;
IMenuOption* Key3;
IMenuOption* Key4;
IMenuOption* Key5;

void Menu()
{
	MainMenu = GPluginSDK->AddMenu("oohmyChatSpammer");
	Enabled = MainMenu->CheckBox("Enabled ", true);

	Settings = MainMenu->AddMenu("Settings");
	Key = Settings->AddKey("L++ OWNS ME", 97);
	Key1 = Settings->AddKey("Cant Cheat on VAC", 98);
	Key2 = Settings->AddKey("Get Good Kids", 99);
	Key3 = Settings->AddKey("Refund Your Cheat", 100);
	Key4 = Settings->AddKey("Middle Finger", 101);
	Key5 = Settings->AddKey("GG Key", 102);
}

void keypress()
{
	if (Enabled->Enabled())
	{
		if (GetAsyncKeyState(Key->GetInteger()))
		{
			GGame->Say("/all LEAGUEPLUSPLUS.NET OWNS ME AND ALL");
			GGame->Say("/all LEAGUEPLUSPLUS.NET OWNS ME AND ALL");
			GGame->Say("/all LEAGUEPLUSPLUS.NET OWNS ME AND ALL");
			GGame->Say("/all LEAGUEPLUSPLUS.NET OWNS ME AND ALL");
			GGame->Say("/all LEAGUEPLUSPLUS.NET OWNS ME AND ALL");
			GGame->Say("/all LEAGUEPLUSPLUS.NET OWNS ME AND ALL");
		}
	}
}

void keypress1()
{
	if (Enabled->Enabled())
	{
		if (GetAsyncKeyState(Key1->GetInteger()))
		{
			GGame->Say("/all You can't cheat on VAC secured servers.");
			GGame->Say("/all You can't cheat on VAC secured servers.");
			GGame->Say("/all You can't cheat on VAC secured servers.");
			GGame->Say("/all You can't cheat on VAC secured servers.");
			GGame->Say("/all You can't cheat on VAC secured servers.");
			GGame->Say("/all You can't cheat on VAC secured servers.");
		}
	}
}

void keypress2()
{
	if (Enabled->Enabled())
	{
		if (GetAsyncKeyState(Key2->GetInteger()))
		{
			GGame->Say("/all If I wanted to suicide, i'd jump from your ego to your elo. Just get good and buy leagueplusplus.net");
			GGame->Say("/all If I wanted to suicide, i'd jump from your ego to your elo. Just get good and buy leagueplusplus.net");
			GGame->Say("/all If I wanted to suicide, i'd jump from your ego to your elo. Just get good and buy leagueplusplus.net");
			GGame->Say("/all If I wanted to suicide, i'd jump from your ego to your elo. Just get good and buy leagueplusplus.net");
			GGame->Say("/all If I wanted to suicide, i'd jump from your ego to your elo. Just get good and buy leagueplusplus.net");
			GGame->Say("/all If I wanted to suicide, i'd jump from your ego to your elo. Just get good and buy leagueplusplus.net");
		}
	}
}

void keypress3()
{
	if (Enabled->Enabled())
	{
		if (GetAsyncKeyState(Key3->GetInteger()))
		{
			GGame->Say("/all refund your inferior cheat");
			GGame->Say("/all refund your inferior cheat");
			GGame->Say("/all refund your inferior cheat");
			GGame->Say("/all refund your inferior cheat");
			GGame->Say("/all refund your inferior cheat");
			GGame->Say("/all refund your inferior cheat");
		}
	}
}

void keypress4()
{
	if (Enabled->Enabled())
	{
		if (GetAsyncKeyState(Key4->GetInteger()))
		{
			GGame->Say("/all ........('(...´...´.... ¯~/'...')");
			GGame->Say("/all .........\.................'...../");
			GGame->Say("/all ..........''...\.......... _.·´");
			GGame->Say("/all ....................../´¯/)");
			GGame->Say("/all ....................,/¯../");
			GGame->Say("/all .................../..../");
			GGame->Say("/all ............./´¯/'...'/´¯¯`·¸");
			GGame->Say("/all ........../'/.../..../......./¨¯\ ");
		}
	}
}

void keypress5()
{
	if (Enabled->Enabled())
	{
		if (GetAsyncKeyState(Key5->GetInteger()))
		{
			GGame->Say("/all __GG_________GG_GG________GG");
			GGame->Say("/all ___GG________GG__GG_______GG");
			GGame->Say("/all _____GGGGGGG_______GGGGGG");
			GGame->Say("/all ______GGGGGG________GGGGGG");
			GGame->Say("/all ____GG_______GG___GG_______GG");
			GGame->Say("/all __GG____________GG");
			GGame->Say("/all _GG____________GG");
			GGame->Say("/all _GG_______GGGG_GG_____GGGG");
		}
	}
}

PLUGIN_EVENT(void) OnGameUpdate()
{
	keypress();
	keypress1();
	keypress2();
	keypress3();
	keypress4();
	keypress5();
}

PLUGIN_API void OnLoad(IPluginSDK* PluginSDK)
{
	PluginSDKSetup(PluginSDK);
	Menu();
	GEventManager->AddEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GGame->PrintChat("<font color=\"#ff0707\"><b>oohmyChatSpammer by </b></font><b><font color=\"#6100ff\">oohmygod </font></b><font color=\"#ff0707\"><b>loaded</b>");
	GGame->Say("/all hvh?");
}

PLUGIN_API void OnUnload()
{
	MainMenu->Remove();
	GEventManager->RemoveEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GGame->PrintChat("<font color=\"#ff0707\"><b>oohmyChatSpammer by </b></font><b><font color=\"#6100ff\">oohmygod </font></b><font color=\"#ff0707\"><b>unloaded</b>");
}