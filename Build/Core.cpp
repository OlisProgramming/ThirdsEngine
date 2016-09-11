#include "Core.h"

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include "Window.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
GLFWwindow* glfwWindow;

Core::Core()
{
}

Core::~Core()
{
}

void Core::start()
{
	if (!Window::createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Thirds Engine | Version 0.1")) {
		return;
	}

	// Set colour to clear screen with
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	do {
		render();
	} while (!Window::isCloseRequested());

	stop();
}

void Core::update()
{
}

void Core::render()
{
	Window::render();
}

void Core::stop()
{
	dispose();
}

void Core::dispose()
{
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}