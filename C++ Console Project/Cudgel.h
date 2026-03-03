#pragma once
#include "Weapon.h"
class Cudgel :
    public Weapon
{
public:
    Cudgel()
    {
        Level = 5;
        MonsterCanUsed = Troll;
        Name = "Cudgel";

        BoniAttackPoints = 15;

        MinStrength = 12;
    }

    Weapon* Clone();
};

