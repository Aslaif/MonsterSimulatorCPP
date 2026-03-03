#include "Troll.h"
#include "TreeTrunk.h"
#include "Cudgel.h"

using namespace std;

void TrollMonster::LevelUp(int levelUp)
{
	cout << "LevelUp" << endl;
	cout << "You have " << levelUp << " Level Pion(s) to change the stats of " << Name << "." << endl;

	cout << "Health: " << HitPoints << " +" << LevelUpHitPoints << " Attack: " << AttackPoints << " +" << LevelUpAttackPoints << " Defence: " << DefencePoints << " +" << LevelUpDefencePoints << " Speed: " << SpeedPoints << " +" << LevelUpSpeedPoints << endl;
	cout << "Strength: " << Strength << " +" << LevelUpStrength << " Dexterity: " << Dexterity << " +" << LevelUpDexterity << endl;

	int statsInput{ 0 };

	for (size_t i = 0; i < levelUp; i++)
	{
		cout << "Choose one stat" << endl;
		cout << "(1) Health, (2) Attack, (3) Defence, (4) Strength" << endl;

		int inputTurn{ 1 };

		do
		{
			if (inputTurn != 1)
				cout << "Pls enter a correct number between 1 and 4 from the options!" << endl;
			else
				cout << "Pls enter the desired stat using their corresponding number!" << endl;

			cin >> statsInput;

			inputTurn++;

		} while (statsInput < 1 || statsInput > 4);

		AddState(statsInput);
	}

	system("cls");

	cout << "The stats of " << Name << " are:" << endl;
	cout << "Health: " << HitPoints << " Attack: " << AttackPoints << " Defence: " << endl;
	cout << "Strength: " << Strength << endl;
	cout << endl;
}

void TrollMonster::AddState(int statsInput)
{
	if (statsInput > 4)
		statsInput = statsInput % 4;

	switch (statsInput)
	{
	case 1:
		HitPoints += LevelUpHitPoints;
		break;
	case 2:
		AttackPoints += LevelUpAttackPoints;
		break;
	case 3:
		DefencePoints += LevelUpDefencePoints;
		break;
	case 4:
		Strength += LevelUpStrength;
		break;
	default:
		break;
	}
}

void TrollMonster::CreateWeapons(int randomValue, int level)
{
	int weaponValue;

	if (level >= Cudgel().Level)
		weaponValue = 3;
	else if (level >= TreeTrunk().Level)
		weaponValue = 2;
	else
		weaponValue = 1;

	int randomRightHand = randomValue % weaponValue;

	switch (randomRightHand)
	{
	case 0:
		RightHand = nullptr;
		break;
	case 1:
		RightHand = new TreeTrunk(); // lvl 3
		break;
	case 2:
		RightHand = new Cudgel();  // lvl 5
		break;
	default:
		break;
	}
}

bool TrollMonster::IsUseableWeapon(Weapon* weapon)
{
	if (weapon->MonsterCanUsed == MonsterType)
	{
		if (Strength >= weapon->MinStrength)
			return true;
	}

	return false;
}

BaseMonster* TrollMonster::Clone()
{
	return new TrollMonster(*this);
}
