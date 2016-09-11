#pragma once
class Renderable
{
public:
	/* Called on every object at a rate of 60Hz (60 FPS) */
	virtual void update() = 0;
	/* Render to the screen */
	virtual void render() = 0;
};

