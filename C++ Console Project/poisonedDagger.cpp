#include "poisonedDagger.h" 

int PoisonedDagger::SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon)
{
    enemyMonster->Poisoned++;

    return 0;
}

Weapon* PoisonedDagger::Clone()
{
    return new PoisonedDagger(*this);
}
