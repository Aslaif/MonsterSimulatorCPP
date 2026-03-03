#include "Dagger.h"

Weapon* Dagger::Clone()
{
    return new Dagger(*this);
}
