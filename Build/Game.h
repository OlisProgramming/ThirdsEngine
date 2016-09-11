#pragma once

#include "Renderable.h"

class Game : public Renderable
{
public:
	Game();
	~Game();

	void input();
	void render();
	void update();
};

