#pragma once

#include "Renderable.h"
#include "ThirdsMesh.h"

class Game : public Renderable
{
public:
	Game();
	~Game();

	void input();
	void update() override;
	void render() override;

private:
	ThirdsMesh mesh;
};

