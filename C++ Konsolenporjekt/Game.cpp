#include "Game.h"
#include "Goblin.h"
#include "Ork.h"
#include "Troll.h"

using namespace std;

void Game::GameLoop()
{
	ChooseOwnFighter();

	cout << endl;

	do
	{
		Fight();

		if (isGameOver)
			LootAndLevel();

	} while (isGameOver);
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
	cout << "Choose your challanger!" << endl;

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

	} while (monsterInput < Goblin || monsterInput > Troll); // warum dreht er am rad bei buchstaben??
	// und warum wealt er nur trolle aus??

	system("cls");

	cout << "You choosed " << ownMonster->Name << " as your Challenger!" << endl;
	cout << "Give it a name" << endl;
	cin >> ownMonster->Name;

	system("cls");

	cout << "Get your Fighter extra power!" << endl;
	cout << "You could invest your Pions in every stat. The stats increase differently per point." << endl;
	ownMonster->LevelUp(3);

	cout << ownMonster->Name << " is ready to fight!" << endl;
}

BaseMonster* Game::RandomEnemyFighter(int level)
{
	srand(static_cast<unsigned int>(time(0)));
	int random = Goblin + (rand() % Troll);
	BaseMonster* monster = CreateMonster((EMonster)random);

	for (size_t i = 0; i < level; i++)
	{
		random = 1 + (rand() % 6);
		monster->AddState(random);
	}

	return monster;
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

	enemyMonster = RandomEnemyFighter(fight);
	cout << "Your enemy is a " << enemyMonster->Name << endl;

	BaseMonster** firstFighter = nullptr;
	BaseMonster** seconFighter = nullptr;

	if (ownMonster->SpeedPoints > enemyMonster->SpeedPoints)
	{
		firstFighter = &ownMonster;  
		seconFighter = &enemyMonster;
	}
	else if (ownMonster->SpeedPoints < enemyMonster->SpeedPoints)
	{
		firstFighter = &enemyMonster;
		seconFighter = &ownMonster;
	}
	else
	{
		srand(static_cast<unsigned int>(time(0)));
		int random = (rand() % 1);
		switch (random)
		{
		case 0:
			firstFighter = &ownMonster;
			seconFighter = &enemyMonster;
			break;
		case 1:
			firstFighter = &enemyMonster;
			seconFighter = &ownMonster;
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

	} while (!(*firstFighter)->IsDead());

	isGameOver = ownMonster->IsDead();
	if (isGameOver)
		cout << "GAME OVER" << endl;
	else
		cout << enemyMonster->Name << " has fallen! " << ownMonster->Name << " win!" << endl;

	cout << "The fight went " << turn << " rounds." << endl;
}

void Game::LootAndLevel()
{
	ownMonster->LevelUp(1);
}
