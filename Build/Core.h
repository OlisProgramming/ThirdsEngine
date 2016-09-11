#pragma once

#include "Game.h"
#include "Renderable.h"
#include "Disposable.h"

class Core : public Renderable, Disposable
{
public:
	Core();
	~Core();

	void start();
	void stop();

private:
	Game game;

	void update();
	void render();
	void dispose();
};