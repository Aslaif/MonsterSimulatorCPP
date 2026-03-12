#pragma once
#include "BaseMonster.h"
class TrollMonster :
	public BaseMonster
{
public:
	TrollMonster()
	{
		HitPoints = 180;
		AttackPoints = 7;
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

	void LevelUp(int levelUp);
	void AddState(int);
	void CreateWeapons(int randomValue, int level);
	bool IsUsableWeapon(Weapon* weapon);

	BaseMonster* Clone();
};

