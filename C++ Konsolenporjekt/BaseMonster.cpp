#include "BaseMonster.h"

using namespace std;

void BaseMonster::Attack(BaseMonster* enemy)
{
	cout << Name << " attack " << enemy->Name << "!" << endl;
	enemy->TakeDamage(AttackPoints, Strength);
}

bool BaseMonster::IsDodge(int strength)
{
	srand(static_cast<unsigned int>(time(0)));
	int random = 1 + (rand() % 20);
	int dodgeValue = SpeedPoints + Dexterity - strength;
	if (dodgeValue > 18)
		dodgeValue = 18;

	if (dodgeValue < random)
		false;

	return true;
}

void BaseMonster::TakeDamage(int attackDamage, int strength)
{
	if (IsDodge(strength))
	{
		cout << Name << " dodge the attack!" << endl;
		return;
	}

	int takeDamage = attackDamage - DefencePoints - (2 * Dexterity);
	if (takeDamage < 0)
		takeDamage = 0;
	HitPoints -= takeDamage += (2 * strength);
	if (HitPoints < 0)
		HitPoints = 0;

	cout << Name << " take " << takeDamage << " damage and still has " << HitPoints << " health pions." << endl;
}

bool BaseMonster::IsDead()
{
	if (HitPoints <= 0)
		return true;

	return false;
}

void BaseMonster::LevelUp(int levelUp)
{
	cout << "LevelUp" << endl;
	cout << "You have " << levelUp << " Level Pion(s) to change the stats of " << Name << "." << endl;

	cout << "Health: " << HitPoints << " +" << LevelUpHitPoints << " Attack: " << AttackPoints << " +" << LevelUpAttackPoints << " Defence: " << DefencePoints << " +" << LevelUpDefencePoints << " Speed: " << SpeedPoints << " +" << LevelUpSpeedPoints << endl;
	cout << "Strength: " << Strength << " +" << LevelUpStrength << " Dexterity: " << Dexterity << " +" << LevelUpDexterity << endl;

	int statsInput{ 0 };

	for (size_t i = 0; i < levelUp; i++)
	{
		cout << "Choose one stat" << endl;
		cout << "(1) Health, (2) Attack, (3) Defence, (4) Speed, (5) Strength, (6) Dexterity" << endl;

		int inputTurn{ 1 };

		do
		{
			if (inputTurn != 1)
				cout << "Pls enter a correct number between 1 and 6 from the options!" << endl;
			else
				cout << "Pls enter the desired stat using their corresponding number!" << endl;

			cin >> statsInput;

			inputTurn++;

		} while (statsInput < 1 || statsInput > 6);

		AddState(statsInput);
	}

	system("cls");

	cout << "The stats of " << Name << " are:" << endl;
	cout << "Health: " << HitPoints << " Attack: " << AttackPoints << " Defence: " << DefencePoints << " Speed: " << SpeedPoints << endl;
	cout << "Strength: " << Strength << " Dexterity: " << Dexterity << endl;
	cout << endl;
}

void BaseMonster::AddState(int statsInput)
{
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
		SpeedPoints += LevelUpSpeedPoints;
		break;
	case 5:
		Strength += LevelUpStrength;
		break;
	case 6:
		Dexterity += LevelUpDexterity;
		break;
	default:
		break;
	}
}
