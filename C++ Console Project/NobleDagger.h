#pragma once
#include "Dagger.h"
#include "BaseMonster.h"

class NobleDagger :
    public Dagger
{
public:
    NobleDagger()
    {
        Level = 3;
        Name = "Noble Dagger";

        BoniAttackPoints = 5;
        BoniSpeedPoints = 2;

        MinDexterity = 8;
    }

    int SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon);

    Weapon* Clone();
};

