#pragma once

#include <glm\glm.hpp>
using namespace glm;

class ThirdsVertex
{
public:
	ThirdsVertex(vec3 pos);
	~ThirdsVertex();

	vec3 getPos();
	void setPos(vec3 pos);

private:
	vec3 pos;
};

