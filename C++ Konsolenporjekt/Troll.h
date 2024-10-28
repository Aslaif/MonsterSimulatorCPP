#pragma once
#include "BaseMonster.h"
class TrollMonster :
	public BaseMonster
{
public:
	TrollMonster()
	{
		HitPoints = 270;
		AttackPoints = 95;
		DefencePoints = 5;
		SpeedPoints = 2;

		Strength = 9;
		Dexterity = 1;

		LevelUpHitPoints = 30;
		LevelUpAttackPoints = 10;
		LevelUpDefencePoints = 3;

		LevelUpStrength = 2;

		MonsterType = Troll;
		Name = "The Troll";
	}
};

