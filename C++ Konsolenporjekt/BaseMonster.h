#pragma once

#include "EMonster.h"
#include <iostream>
#include <string>	

class BaseMonster
{
public:
	int HitPoints{ 10 };
	int AttackPoints{ 1 };
	int DefencePoints{ 1 };
	int SpeedPoints{ 1 };

	int Strength{ 1 };
	int Dexterity{ 1 };

	int LevelUpHitPoints{ 25 };
	int LevelUpAttackPoints{ 5 };
	int LevelUpDefencePoints{ 5 };
	int LevelUpSpeedPoints{ 1 };

	int LevelUpStrength{ 1 };
	int LevelUpDexterity{ 1 };

	EMonster MonsterType;
	std::string Name;

	virtual void Attack(BaseMonster* enemy);
	virtual void TakeDamage(int attackDamage, int strength);
	virtual bool IsDead();
	virtual void LevelUp(int levelUp);
	virtual void AddState(int);

private:
	virtual bool IsDodge(int strenght);
};

