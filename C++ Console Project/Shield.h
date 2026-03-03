#pragma once
#include "Weapon.h"
class Shield :
	public Weapon
{
public:
	Shield()
	{
        Level = 1;
        MonsterCanUsed = Ork;
        Name = "Shield";

        BoniDefencePoints = 5;

        MinStrength = 5;
	}

    Weapon* Clone();
};

