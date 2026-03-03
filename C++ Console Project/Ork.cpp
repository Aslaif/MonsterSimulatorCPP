#include "Ork.h"
#include "Shield.h"
#include "SerradedSword.h"
#include "Utility.h"

using namespace std;

bool OrkMonster::IsDodge(int strength)
{
	srand(static_cast<unsigned int>(time(0)));
	int random = 1 + (rand() % 20);

	if (dynamic_cast<Shield*>(LeftHand) || dynamic_cast<Shield*>(RightHand))
	{
		srand(static_cast<unsigned int>(time(0)));
		int randomShield = 1 + (rand() % 100);

		int ShieldBoni{ 0 };

		if (LeftHand != nullptr)
			ShieldBoni += LeftHand->BoniDefencePoints;
		if (RightHand != nullptr)
			ShieldBoni += RightHand->BoniDefencePoints;

		if (RandomInt(1, 100) <= 20 + ShieldBoni)
		{
			cout << Name << " blocks the attack!" << endl;
			return true;
		}
	}

	int dodgeValue = SpeedPoints + Dexterity - strength;
	if (dodgeValue > 18)
		dodgeValue = 18;

	if (dodgeValue < RandomInt(1, 20))
		return false;

	cout << Name << " dodge the attack!" << endl;
	return true;
}

void OrkMonster::CreateWeapons(int randomValue, int level)
{
	int weaponValue;

	if (level >= 4)
		weaponValue = 4;
	else
		weaponValue = 3;

	int randomRightHand = randomValue % weaponValue;

	switch (randomRightHand)
	{
	case 0:
		RightHand = nullptr;
		break;
	case 1:
		RightHand = new Sword();
		break;
	case 2:
		RightHand = new Shield();
		break;
	case 3:
		RightHand = new SerradedSword(); // lvl 4
		break;
	default:
		break;
	}

	if (level >= 3)
		level -= 2;

	if (level >= 4)
		weaponValue = 4;
	else
		weaponValue = 3;

	int randomLeftHand = randomValue % weaponValue;

	switch (randomLeftHand)
	{
	case 0:
		LeftHand = nullptr;
		break;
	case 1:
		LeftHand = new Sword();
		break;
	case 2:
		LeftHand = new Shield();
		break;
	case 3:
		LeftHand = new SerradedSword(); // lvl 4
		break;
	default:
		break;
	}
}

BaseMonster* OrkMonster::Clone()
{
	return new OrkMonster(*this);
}
