#include "SerradedSword.h"

int SerradedSword::SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon)
{
    enemyMonster->Bleeding++;

    return 0;
}

Weapon* SerradedSword::Clone()
{
    return new SerradedSword(*this);
}
