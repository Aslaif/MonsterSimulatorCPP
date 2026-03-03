#pragma once

#include "BaseMonster.h"
#include <vector>	
#include "Weapon.h"
#include "Utility.h"

class Game
{
private:
	int turn{ 0 };
	int fight{ 0 };
	BaseMonster* ownMonster = nullptr;
	BaseMonster* enemyMonster = nullptr;
	bool isGameOver;

public:
	void GameLoop();

private:
	void ChooseOwnFighter();
	BaseMonster* RandomEnemyFighter(int);
	Weapon* CreateRandomWeapon(BaseMonster*, int);
	BaseMonster* CreateMonster(EMonster);
	void Fight();
	void LootAndLevel();
	void Loot(Weapon* weapon);
};

