#include "Game.h"
#include "Goblin.h"
#include "Ork.h"
#include "Troll.h"
#include <conio.h>

using namespace std;

void Game::GameLoop()
{
	ChooseOwnFighter();

	cout << endl;

	do
	{
		Fight();

		if (!isGameOver)
			LootAndLevel();

	} while (!isGameOver);

	cout << "GAME OVER" << endl;
}

void Game::ChooseOwnFighter()
{
	cout << "First, choose your own Monster." << endl;
	cout << "Monsters have different stats." << endl;

	for (int i = Goblin; i <= Troll; i++)
	{
		cout << endl;
		ownMonster = CreateMonster((EMonster)i);
		cout << ownMonster->Name << ":" << endl;
		cout << "Health: " << ownMonster->HitPoints << " Attack: " << ownMonster->AttackPoints << " Defence: " << ownMonster->DefencePoints << " Speed: " << ownMonster->SpeedPoints << endl;
		cout << "Strength: " << ownMonster->Strength << " Dexterity: " << ownMonster->Dexterity << endl;
	}

	cout << endl;
	cout << "Choose your challenger!" << endl;

	for (int i = Goblin; i <= Troll; i++)
	{
		ownMonster = CreateMonster((EMonster)i);
		cout << "(" << i << ") " << ownMonster->Name << ", ";
	}
	cout << endl;

	int monsterInput{ 0 };
	int inputTurn{ 1 };

	do
	{
		if (inputTurn != 1)
			cout << "Pls enter a correct number between " << Goblin << " and " << Troll << " from the options!" << endl;
		else
			cout << "Pls enter the desired monster using their corresponding number!" << endl;

		cin >> monsterInput;

		ownMonster = CreateMonster((EMonster)monsterInput);

		inputTurn++;

	} while (monsterInput < Goblin || monsterInput > Troll);

	system("cls");

	cout << "You chose " << ownMonster->Name << " as your Challenger!" << endl;
	cout << "Give it a name" << endl;
	cin >> ownMonster->Name;

	system("cls");

	cout << "Get your Fighter extra power!" << endl;
	cout << "You could invest your Points in every stat. The stats increase differently per point." << endl;
	ownMonster->LevelUp(3);

	cout << ownMonster->Name << " is ready to fight!" << endl;
}

BaseMonster* Game::RandomEnemyFighter(int level)
{
	BaseMonster* monster = CreateMonster((EMonster)RandomInt(Goblin, Troll));

	CreateRandomWeapon(monster, level);

	for (size_t i = 0; i < level; i++)
	{
		monster->AddState(RandomInt(1, 6));
	}

	return monster;
}

Weapon* Game::CreateRandomWeapon(BaseMonster* monster, int level)
{
	Weapon* weapon = nullptr;

	monster->CreateWeapons(RandomInt(1, 100), level); 

	return nullptr;
}

BaseMonster* Game::CreateMonster(EMonster monsterID)
{
	BaseMonster* monster = nullptr;

	switch (monsterID)
	{
	case Goblin:
		monster = new GoblinMonster();
		break;
	case Ork:
		monster = new OrkMonster();
		break;
	case Troll:
		monster = new TrollMonster();
		break;
	default:
		break;
	}

	return monster;
}

void Game::Fight()
{
	fight++;
	turn = 0;

	BaseMonster* CopyOfOwnMonster = ownMonster->Clone();

	safeDelete(enemyMonster);
	enemyMonster = RandomEnemyFighter(fight);
	cout << "Your enemy is " << enemyMonster->Name << endl;

	CopyOfOwnMonster->BuffByWeapons();
	enemyMonster->BuffByWeapons();

	BaseMonster** firstFighter = nullptr;
	BaseMonster** seconFighter = nullptr;

	if (CopyOfOwnMonster->SpeedPoints > enemyMonster->SpeedPoints)
	{
		firstFighter = &CopyOfOwnMonster;
		seconFighter = &enemyMonster;
	}
	else if (CopyOfOwnMonster->SpeedPoints < enemyMonster->SpeedPoints)
	{
		firstFighter = &enemyMonster;
		seconFighter = &CopyOfOwnMonster;
	}
	else
	{
		switch (RandomInt(0, 1))
		{
		case 0:
			firstFighter = &CopyOfOwnMonster;
			seconFighter = &enemyMonster;
			break;
		case 1:
			firstFighter = &enemyMonster;
			seconFighter = &CopyOfOwnMonster;
			break;
		default:
			break;
		}
	}

	do
	{
		turn++;

		(*firstFighter)->Attack((*seconFighter));

		if ((*seconFighter)->IsDead())
			break;

		(*seconFighter)->Attack((*firstFighter));

		(*seconFighter)->StatusEffect();
		(*firstFighter)->StatusEffect();

		auto ch = _getch();

	} while (!(*firstFighter)->IsDead());

	isGameOver = CopyOfOwnMonster->IsDead();
	if (!isGameOver)
		cout << enemyMonster->Name << " has fallen! " << CopyOfOwnMonster->Name << " wins!" << endl;

	cout << "The fight went " << turn << " rounds." << endl;
}

void Game::LootAndLevel()
{
	auto ch = _getch();
	system("cls");

	if (enemyMonster->RightHand != nullptr)
	{
		if (ownMonster->IsUsableWeapon(enemyMonster->RightHand))
			Loot(enemyMonster->RightHand);
	}

	cout << endl;

	if (enemyMonster->LeftHand != nullptr)
	{
		if (ownMonster->IsUsableWeapon(enemyMonster->LeftHand))
			Loot(enemyMonster->LeftHand);
	}

	system("cls");

	ownMonster->LevelUp(1);
}

void Game::Loot(Weapon* weapon)
{
	cout << enemyMonster->Name << " had a " << weapon->Name << "." << endl;
	cout << "extra Health: " << weapon->BoniHitPoints << " extra Attack: " << weapon->BoniAttackPoints << " extra Defence: " << weapon->BoniDefencePoints << " Speed: " << weapon->BoniSpeedPoints << endl;
	cout << endl;

	cout << "The weapon(s) of " << ownMonster->Name << " are: " << endl;
	if (ownMonster->RightHand != nullptr)
	{
		cout << "on the right hand: " << ownMonster->RightHand->Name << endl;
		cout << "extra Health: " << ownMonster->RightHand->BoniHitPoints << " extra Attack: " << ownMonster->RightHand->BoniAttackPoints << " extra Defence: " << ownMonster->RightHand->BoniDefencePoints << " Speed: " << ownMonster->RightHand->BoniSpeedPoints << endl;
	}

	if (ownMonster->LeftHand != nullptr)
	{
		cout << "on the left hand: " << ownMonster->LeftHand->Name << endl;
		cout << "extra Health: " << ownMonster->LeftHand->BoniHitPoints << " extra Attack: " << ownMonster->LeftHand->BoniAttackPoints << " extra Defence: " << ownMonster->LeftHand->BoniDefencePoints << " Speed: " << ownMonster->LeftHand->BoniSpeedPoints << endl;
	}

	cout << endl;
	int input{ 0 };

	cout << "Choose one option" << endl;
	cout << "(1) equip right hand, (2) equip left hand, (3) not equip" << endl;

	int inputTurn{ 1 };

	do
	{
		if (inputTurn != 1)
			cout << "Please enter a correct number between 1 and 3 from the options!" << endl;
		else
			cout << "Please enter the desired stat using their corresponding number!" << endl;

		cin >> input;

		inputTurn++;

	} while (input < 1 || input > 3);

	switch (input)
	{
	case 1:
		safeDelete(ownMonster->RightHand);
		ownMonster->RightHand = weapon->Clone();
		break;
	case 2:
		safeDelete(ownMonster->LeftHand);
		ownMonster->LeftHand = weapon->Clone();
		break;
	case 3:
		break;
	default:
		break;
	}
}
