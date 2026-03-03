#pragma once
#include "Dagger.h"
#include "BaseMonster.h"

class SerradedDagger :
    public Dagger
{
public:
    SerradedDagger()
    {
        Level = 2;
        Name = "Serraded Dagger";

        BoniAttackPoints = 5;
        BoniSpeedPoints = 1;

        MinDexterity = 6;
    }

    int SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon);

    Weapon* Clone();
};

