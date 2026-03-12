#pragma once

#include "EMonster.h"
#include "Weapon.h"
#include <iostream>
#include <string>	
#include <list>
#include "Utility.h"

class BaseMonster
{
public:
	int HitPoints{ 10 };
	int AttackPoints{ 1 };
	int DefencePoints{ 1 };
	int SpeedPoints{ 1 };

	int Strength{ 1 };
	int Dexterity{ 1 };

	int Bleeding{ 0 };
	int Poisoned{ 0 };

	int LevelUpHitPoints{ 25 };
	int LevelUpAttackPoints{ 5 };
	int LevelUpDefencePoints{ 5 };
	int LevelUpSpeedPoints{ 1 };

	int LevelUpStrength{ 1 };
	int LevelUpDexterity{ 1 };

	EMonster MonsterType;
	std::string Name;

	Weapon* RightHand = nullptr;
	Weapon* LeftHand = nullptr;

	virtual void Attack(BaseMonster* enemy);
	virtual bool IsDodge(int strenght);
	virtual void TakeDamage(int attackDamage, int strength, int weapon);
	virtual void StatusEffect();
	virtual bool IsDead();
	virtual void LevelUp(int levelUp);
	virtual void AddState(int);
	virtual void BuffByWeapons();
	virtual void CreateWeapons(int randomValue, int level) = 0; 
	virtual bool IsUsableWeapon(Weapon* weapon);
	virtual BaseMonster* Clone() = 0;

	~BaseMonster();
};

