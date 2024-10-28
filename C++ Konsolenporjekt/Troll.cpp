#include "Troll.h"

using namespace std;

//void BaseMonster::LevelUp(int levelUp)
//{
//	cout << "LevelUp" << endl;
//	cout << "You have " << levelUp << " Level Pion(s) to change the stats of " << Name << "." << endl;
//
//	cout << "Health: " << HitPoints << " +" << LevelUpHitPoints << " Attack: " << AttackPoints << " +" << LevelUpAttackPoints << " Defence: " << DefencePoints << " +" << LevelUpDefencePoints << " Speed: " << SpeedPoints << " +" << LevelUpSpeedPoints << endl;
//	cout << "Strength: " << Strength << " +" << LevelUpStrength << " Dexterity: " << Dexterity << " +" << LevelUpDexterity << endl;
//
//	int statsInput{ 0 };
//
//	for (size_t i = 0; i < levelUp; i++)
//	{
//		cout << "Choose one stat" << endl;
//		cout << "(1) Health, (2) Attack, (3) Defence, (4) Strength" << endl;
//
//		int inputTurn{ 1 };
//
//		do
//		{
//			if (inputTurn != 1)
//				cout << "Pls enter a correct number between 1 and 4 from the options!" << endl;
//			else
//				cout << "Pls enter the desired stat using their corresponding number!" << endl;
//
//			cin >> statsInput;
//
//			inputTurn++;
//
//		} while (statsInput < 1 || statsInput > 6);
//
//		AddState(statsInput);
//	}
//
//	system("cls");
//
//	cout << "The stats of " << Name << " are:" << endl;
//	cout << "Health: " << HitPoints << " Attack: " << AttackPoints << " Defence: " << endl;
//	cout << "Strength: " << Strength << endl;
//	cout << endl;
//}
//
//void BaseMonster::AddState(int statsInput)
//{
//	switch (statsInput)
//	{
//	case 1:
//		HitPoints += LevelUpHitPoints;
//		break;
//	case 2:
//		AttackPoints += LevelUpAttackPoints;
//		break;
//	case 3:
//		DefencePoints += LevelUpDefencePoints;
//		break;
//	case 4:
//		Strength += LevelUpStrength;
//		break;
//	default:
//		break;
//	}
//}