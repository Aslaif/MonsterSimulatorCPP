#include "SerradedDagger.h"

int SerradedDagger::SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon)
{
    enemyMonster->Bleeding++;

    return 0;
}

Weapon* SerradedDagger::Clone()
{
    return new SerradedDagger(*this);
}
