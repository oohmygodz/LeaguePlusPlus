#include "PluginSDK.h"
#include "Common.h"

ISpell2* Q;
ISpell2* W;
ISpell2* E;
ISpell2* R;

IMenu* MainMenu;
IMenu* ComboSettings;
IMenu* Drawings;
IMenu* Killsteal;
IMenu* JungleSettings;

IMenuOption* ComboQ;
IMenuOption* ComboW;
IMenuOption* ComboE;
IMenuOption* ComboR;

IMenuOption* JGQ;
IMenuOption* JGW;
IMenuOption* JGE;

IMenuOption* DrawReady;
IMenuOption* DrawQ;
IMenuOption* DrawW;
IMenuOption* DrawE;
IMenuOption* DrawR;

IMenuOption* KSQ;
IMenuOption* KSE;


PluginSetup("oohmyNunu")

void Menu()
{
	MainMenu = GPluginSDK->AddMenu("oohmynunu");

	ComboSettings = MainMenu->AddMenu("Combo");
	{
		ComboQ = ComboSettings->CheckBox("Use Q", true);
		ComboW = ComboSettings->CheckBox("Use W", true);
		ComboE = ComboSettings->CheckBox("Use E", true);
		//ComboQ = ComboSettings->CheckBox("Use R", true);
	}
	JungleSettings = MainMenu->AddMenu("Jungle");
	{
		JGQ = JungleSettings->CheckBox("Use Q", true);
		JGW = JungleSettings->CheckBox("Use W", true);
		JGE = JungleSettings->CheckBox("Use E", true);
	}
	Killsteal = MainMenu->AddMenu("KS");
	{
		KSQ = Killsteal->CheckBox("KS Q", true);
		KSE = Killsteal->CheckBox("KS E", true);
	}
	Drawings = MainMenu->AddMenu("Drawings");
	{
		DrawReady = Drawings->CheckBox("Draw Only Ready Spells", true);
		DrawQ = Drawings->CheckBox("Draw Q", true);
		DrawW = Drawings->CheckBox("Draw W", true);
		DrawE = Drawings->CheckBox("Draw E", true);
		DrawR = Drawings->CheckBox("Draw R", true);
	}

}

void Spells()
{
	Q = GPluginSDK->CreateSpell2(kSlotQ, kTargetCast, false, false, (kCollidesWithNothing));
	Q->SetSkillshot(0.25f, 0.f, 1000.f, 125.f);


	W = GPluginSDK->CreateSpell2(kSlotW, kTargetCast, false, false, (kCollidesWithNothing));
	W->SetSkillshot(0.25f, 0.f, 1000.f, 700.f);


	E = GPluginSDK->CreateSpell2(kSlotE, kTargetCast, true, false, (kCollidesWithYasuoWall));
	E->SetSkillshot(0.25f, 0.f, 1000.f, 550.f);


	R = GPluginSDK->CreateSpell2(kSlotR, kCircleCast, false, true, (kCollidesWithNothing));
	R->SetSkillshot(0.25f, 650.f, 1000.f, 650.f);
}

void LaneClear()
{
	for (auto minion : GEntityList->GetAllMinions(false, false, true))
	{
		if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, 750))
		{
			if (JGQ->Enabled() && Q->IsReady())
			{
				Q->CastOnTarget(minion);
			}
			if (JGW->Enabled() && W->IsReady())
			{
				E->CastOnTarget(minion);
			}
			if (JGE->Enabled() && E->IsReady())
			{
				E->CastOnTarget(minion);
			}
		}
	}
}




void KS()
{
	for (auto t : GEntityList->GetAllHeros(false, true))
	{
		if (Q->IsReady() && KSQ->Enabled())
		{
			auto dmg = GHealthPrediction->GetKSDamage(t, kSlotQ, Q->GetDelay(), true);
			if (t->GetHealth() <= dmg)
			{
				Q->CastOnTarget(t);
			}
		}

		if (E->IsReady() && KSE->Enabled())
		{
			auto dmg = GHealthPrediction->GetKSDamage(t, kSlotQ, Q->GetDelay(), true);
			if (t->GetHealth() <= dmg)
			{
				Q->CastOnTarget(t);
			}
		}
	}
}


PLUGIN_EVENT(void) OnGame()
{
	KS();
	auto t = GTargetSelector->FindTarget(QuickestKill, SpellDamage, 550);
	if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
	{
		if (Q->IsReady() && ComboQ->Enabled())
		{
			Q->CastOnTarget(t);
		}
		if (W->IsReady() && ComboW->Enabled() && GetEnemiesInRange(700) >= 3)
		{
			W->CastOnPlayer();
		}
		if (E->IsReady() && ComboE->Enabled())
		{
			E->CastOnTarget(t);
		}
	}
	if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
	{
		LaneClear();
	}
}

PLUGIN_EVENT(void) OnRender()
{
	if (DrawReady->Enabled())
	{
		if (Q->IsReady() && DrawQ->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), Q->Range()); }

		if (E->IsReady() && DrawE->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), E->Range()); }

		if (W->IsReady() && DrawW->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), W->Range()); }

		if (R->IsReady() && DrawW->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), R->Range()); }

	}
	else
	{
		if (DrawQ->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), Q->Range()); }

		if (DrawE->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), E->Range()); }

		if (DrawW->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), W->Range()); }

		if (DrawR->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), R->Range()); }
	}
}

PLUGIN_API void OnLoad(IPluginSDK* PluginSDK)
{
	PluginSDKSetup(PluginSDK);
	Menu();
	Spells();


	GEventManager->AddEventHandler(kEventOnGameUpdate, OnGame);
	GEventManager->AddEventHandler(kEventOnRender, OnRender);
}

PLUGIN_API void OnUnload()
{
	MainMenu->Remove();


	GEventManager->RemoveEventHandler(kEventOnGameUpdate, OnGame);;
	GEventManager->RemoveEventHandler(kEventOnRender, OnRender);


}