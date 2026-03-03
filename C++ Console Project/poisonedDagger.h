#pragma once
#include "Dagger.h"
#include "BaseMonster.h"

class PoisonedDagger :
    public Dagger
{
public:
    PoisonedDagger()
    {
        Level = 5;
        Name = "Poisoned Dagger";

        BoniAttackPoints = 5;
        BoniSpeedPoints = 2;

        MinDexterity = 10;
    }

    int SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon);

    Weapon* Clone();
};

