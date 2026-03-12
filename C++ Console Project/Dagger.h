#pragma once
#include "Weapon.h"

class Dagger :
    public Weapon
{
public:
    Dagger()
    {
        Level = 1;
        AllowedMonsterType = Goblin;
        Name = "Dagger";

        BoniAttackPoints = 5;
        BoniSpeedPoints = 1;

        MinDexterity = 6;
    }

    Weapon* Clone();
};

