#pragma once
#include "Cudgel.h"
class TreeTrunk :
    public Cudgel
{
public:
    TreeTrunk()
    {
        Level = 3;
        MonsterCanUsed = Troll;
        Name = "Tree Trunk";

        BoniAttackPoints = 11;
        BoniSpeedPoints = -1;

        MinStrength = 10;
    }

    Weapon* Clone();
};

