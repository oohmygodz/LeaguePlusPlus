#pragma once
#include "PluginSDK.h"

int GetEnemiesInRange(float range)
{
	int enemies = 0;
	for (auto enemy : GEntityList->GetAllHeros(false, true))
	{
		if (enemy != nullptr && GEntityList->Player()->IsValidTarget(enemy, range))
			enemies++;
	}
	return enemies;
}