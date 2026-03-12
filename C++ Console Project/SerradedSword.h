#pragma once
#include "Sword.h"
#include "BaseMonster.h"

class SerradedSword :
    public Sword
{
public:
    SerradedSword()
    {
        Level = 4;
        AllowedMonsterType = AllTypes;
        Name = "Serraded Sword";

        BoniAttackPoints = 12;

        MinStrength = 6;
    }

    int SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon);

    Weapon* Clone();
};

