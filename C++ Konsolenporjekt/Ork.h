#pragma once
#include "BaseMonster.h"
class OrkMonster :
	public BaseMonster
{
public:
	OrkMonster()
	{
		HitPoints = 130;
		AttackPoints = 55;
		DefencePoints = 20;
		SpeedPoints = 5;

		Strength = 5;
		Dexterity = 3;

		LevelUpAttackPoints = 8;
		LevelUpDefencePoints = 8;

		MonsterType = Ork;
		Name = "The Ork";
	}
};

