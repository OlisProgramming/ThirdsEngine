#pragma once

#include <GL\glew.h>
#include "Renderable.h"
#include "ThirdsVertex.h"

class ThirdsMesh : public Renderable
{
public:
	ThirdsMesh();
	~ThirdsMesh();
	void addVertices(ThirdsVertex vertices[]);
	virtual void update() override;
	virtual void render() override;

private:
	GLuint vbo;
	int size;
};

