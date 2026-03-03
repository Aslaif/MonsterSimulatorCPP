#include "Sword.h"

Weapon* Sword::Clone()
{
    return new Sword(*this);
}
