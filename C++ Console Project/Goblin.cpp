#include "Goblin.h"
#include "Weapon.h"
#include "SerradedDagger.h"
#include "NobleDagger.h" 
#include "SerradedSword.h"
#include "poisonedDagger.h"

void GoblinMonster::CreateWeapons(int randomValue, int level) 
{
	int weaponValue;

	switch (level)
	{
	case 4:
		weaponValue = 6;
		break;
	case 3:
		weaponValue = 5;
		break;
	case 2:
		weaponValue = 4;
		break;
	case 1:
		weaponValue = 3;
		break;
	default:
		weaponValue = 7;
		break;
	}

	int randomRightHand = randomValue % weaponValue;

	switch (randomRightHand)
	{
	case 0:
		RightHand = nullptr;
		break;
	case 1:
		RightHand = new Dagger();
		break;
	case 2:
		RightHand = new Sword();
		break;
	case 3:
		RightHand = new SerradedDagger(); // lvl 2
		break;
	case 4:
		RightHand = new NobleDagger(); // lvl 3
		break;
	case 5:
		RightHand = new SerradedSword(); // lvl 4
		break;
	case 6:
		RightHand = new PoisonedDagger(); // lvl 5
	default:
		break;
	}

	if (level >= 3)
		level -= 2;

	switch (level)
	{
	case 4:
		weaponValue = 6;
		break;
	case 3:
		weaponValue = 5;
		break;
	case 2:
		weaponValue = 4;
		break;
	case 1:
		weaponValue = 3;
		break;
	default:
		weaponValue = 7;
		break;
	}

	int randomLeftHand = randomValue % weaponValue;

	switch (randomLeftHand)
	{
	case 0:
		LeftHand = nullptr;
		break;
	case 1:
		LeftHand = new Dagger();
		break;
	case 2:
		LeftHand = new Sword();
		break;
	case 3:
		LeftHand = new SerradedDagger(); // lvl 2
		break;
	case 4:
		LeftHand = new NobleDagger(); // lvl 3
		break;
	case 5:
		LeftHand = new SerradedSword(); // lvl 4
		break;
	case 6:
		LeftHand = new PoisonedDagger(); // lvl 5
	default:
		break;
	}
}

BaseMonster* GoblinMonster::Clone()
{
	return new GoblinMonster(*this);
}
