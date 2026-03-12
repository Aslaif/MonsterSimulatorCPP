#pragma once
#include "Weapon.h"
class Sword :
    public Weapon
{
public:
    Sword()
    {
        Level = 1;
        AllowedMonsterType = AllTypes;
        Name = "Sword";

        BoniAttackPoints = 10;

        MinStrength = 3;
    }

    Weapon* Clone();
};

