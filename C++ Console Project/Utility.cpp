#include "Utility.h"

int RandomInt(int min, int max)
{
	random_device random;
	mt19937 mt(random());
	uniform_int_distribution<> distribution(min, max);
	return distribution(mt);
}
