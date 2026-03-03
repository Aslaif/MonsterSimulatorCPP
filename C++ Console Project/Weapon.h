#pragma once

#include <string>
#include "EMonster.h"

class BaseMonster;
class Weapon
{
public:
	int Level{ 1 };
	EMonster MonsterCanUsed;
	std::string Name;

	int BoniHitPoints{ 0 };
	int BoniAttackPoints{ 0 };
	int BoniDefencePoints{ 0 };
	int BoniSpeedPoints{ 0 };

	int MinStrength{ 0 };
	int MinDexterity{ 0 };

	virtual int SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon);
	virtual void BuffMonster(BaseMonster* monsterWithWeapon);

	virtual Weapon* Clone() = 0;
};

