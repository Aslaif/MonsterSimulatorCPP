#include "NobleDagger.h"

int NobleDagger::SpecialEffect(BaseMonster* enemyMonster, BaseMonster* monsterWithWeapon)
{
	return monsterWithWeapon->Dexterity;
}

Weapon* NobleDagger::Clone()
{
	return new NobleDagger(*this);
}
