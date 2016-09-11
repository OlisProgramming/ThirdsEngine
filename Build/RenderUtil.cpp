#include "RenderUtil.h"

#include <glfw3.h>

void RenderUtil::cls()
{
	// Stencil buffer??
	glClear(GL_COLOR_BUFFER_BIT);
}

void RenderUtil::initGraphics()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);

	// Depth clamp?
	// sRGB colour space?
}