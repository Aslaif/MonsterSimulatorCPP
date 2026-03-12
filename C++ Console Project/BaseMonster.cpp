#include "BaseMonster.h"
#include "Utility.h"

using namespace std;

void BaseMonster::Attack(BaseMonster* enemy)
{
	cout << Name << " attacks " << enemy->Name << "!" << endl;

	if (enemy->IsDodge(Strength))
		return;

	int weaponBoni = 0;

	if (LeftHand != nullptr)
		weaponBoni += LeftHand->SpecialEffect(enemy, this);

	if (RightHand != nullptr)
		weaponBoni += RightHand->SpecialEffect(enemy, this);

	enemy->TakeDamage(AttackPoints, Strength, weaponBoni);
}

bool BaseMonster::IsDodge(int strength)
{
	int dodgeValue = SpeedPoints + Dexterity - strength;
	if (dodgeValue > 18)
		dodgeValue = 18;

	if (dodgeValue < RandomInt(1, 20))
		return false;

	cout << Name << " dodges the attack!" << endl;
	return true;
}

void BaseMonster::TakeDamage(int attackDamage, int strength, int weapon)
{
	int takeDamage = attackDamage + weapon - DefencePoints - (2 * Dexterity);
	if (takeDamage < 0)
		takeDamage = 0;
	HitPoints -= takeDamage += (2 * strength);
	if (HitPoints < 0)
		HitPoints = 0;

	cout << Name << " takes " << takeDamage << " damage and still has " << HitPoints << " health pions." << endl;
}

void BaseMonster::StatusEffect()
{
	if (Bleeding > 0)
	{
		HitPoints -= Bleeding;
		cout << Name << " takes " << Bleeding << " damage due to bleeding and still has " << HitPoints << " health pions." << endl;
	}

	if (Poisoned > 0)
	{

		if (RandomInt(0, 1) == 1)
		{
			if (Dexterity >= 1)
			{
				Dexterity -= Poisoned;
				cout << Name << " loses " << Poisoned << " points of dexterity due to poisoning and still has " << Dexterity << " dexterity." << endl;
			}
			else if (Strength >= 1)
			{
				Strength -= Poisoned;
				cout << Name << " loses " << Poisoned << " points of strength due to poisoning and still has " << Strength << " strength." << endl;
			}
			else
			{
				Poisoned = 0;
				return;
			}
		}
		else
		{
			if (Strength >= 1)
			{
				Strength -= Poisoned;
				cout << Name << " loses " << Poisoned << " points of strength due to poisoning and still has " << Strength << " strength." << endl;
			}
			else if (Dexterity >= 1)
			{
				Dexterity -= Poisoned;
				cout << Name << " loses " << Poisoned << " points of dexterity due to poisoning and still has " << Dexterity << " dexterity." << endl;
			}
			else
			{
				Poisoned = 0;
				return;
			}
		}
	}
}

bool BaseMonster::IsDead()
{
	if (HitPoints <= 0)
		return true;

	return false;
}

void BaseMonster::LevelUp(int levelUp)
{
	cout << "Level Up" << endl;
	cout << "You have " << levelUp << " Level Point(s) to change the stats of " << Name << "." << endl;

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
				cout << "Please enter a correct number between 1 and 6 from the options!" << endl;
			else
				cout << "Please enter the desired stat using their corresponding number!" << endl;

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
	if (statsInput > 6)
		statsInput = statsInput % 6;

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

void BaseMonster::BuffByWeapons()
{
	if (LeftHand != nullptr)
	{
		HitPoints += LeftHand->BoniHitPoints;
		AttackPoints += LeftHand->BoniAttackPoints;
		DefencePoints += LeftHand->BoniDefencePoints;
		SpeedPoints += LeftHand->BoniSpeedPoints;
	}

	if (RightHand != nullptr)
	{
		HitPoints += RightHand->BoniHitPoints;
		AttackPoints += RightHand->BoniAttackPoints;
		DefencePoints += RightHand->BoniDefencePoints;
		SpeedPoints += RightHand->BoniSpeedPoints;
	}
}

void BaseMonster::CreateWeapons(int randomValue, int level)
{

}

bool BaseMonster::IsUsableWeapon(Weapon* weapon)
{
	if (weapon->AllowedMonsterType == MonsterType || weapon->AllowedMonsterType == AllTypes)
	{
		if (Strength >= weapon->MinStrength && Dexterity >= weapon->MinDexterity)
			return true;
	}

	return false;
}

BaseMonster::~BaseMonster()
{
	safeDelete(RightHand);
	safeDelete(LeftHand);
}

