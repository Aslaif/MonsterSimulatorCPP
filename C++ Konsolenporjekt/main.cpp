#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	cout << "Welcome to the Monster Fight Arena!" << endl;

	Game game;
	game.GameLoop();

	return 0;

	// warum ist es ein endloser fight??
	// warum funktionieren die veraenderten troll methoden nicht??
}
