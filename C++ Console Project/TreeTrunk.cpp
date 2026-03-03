#include "TreeTrunk.h"

Weapon* TreeTrunk::Clone()
{
    return new TreeTrunk(*this);
}
