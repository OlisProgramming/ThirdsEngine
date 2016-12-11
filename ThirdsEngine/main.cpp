#include <stdio.h>

#include "GameManager.h"
#undef main

using namespace te;

int main() {

	// GameManager does nothing until run is called.
	GameManager manager;
	manager.setWindow(new Window(800, 600));
	manager.run();

	return 0;
}