#pragma once

#include "Renderable.h"
#include "Disposable.h"

class Core : public Renderable, Disposable
{
public:
	Core();
	~Core();

	void start();

	void update();
	void render();

	void stop();
	void dispose();
};