#pragma once
#include <random>
#include <iostream>

using namespace std;

template<typename T>
void safeDelete(T*& obj)
{
	if (obj = nullptr) return;

	delete obj;
	obj = nullptr;
}

int RandomInt(int min, int max);


