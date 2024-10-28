#pragma once

#include "BaseMonster.h"

class GoblinMonster :
	public BaseMonster
{
public:
	GoblinMonster()
	{
		HitPoints = 100;
		AttackPoints = 40;
		DefencePoints = 15;
		SpeedPoints = 8;  

		Strength = 2; 
		Dexterity = 6; 

		LevelUpHitPoints = 20;

		LevelUpDexterity = 2;

		MonsterType = Goblin;
		Name = "The Goblin";
	}
};

