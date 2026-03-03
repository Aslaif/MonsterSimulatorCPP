#include "Cudgel.h"

Weapon* Cudgel::Clone()
{
    return new Cudgel(*this);
}
