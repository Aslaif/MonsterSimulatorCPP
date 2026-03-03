#include "Shield.h"

Weapon* Shield::Clone()
{
    return new Shield(*this);
}
