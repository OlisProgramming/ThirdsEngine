// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include "../../Build/Window.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
GLFWwindow* glfwWindow;

int main(int argc, char* argv[]) {
	
	if (!Window::createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Thirds Engine | Version 0.1"))
		return -1;

	// Set colour to clear screen with
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	do {
		Window::render();
	} // Check if the ESC key was pressed or the window was closed
	while (!Window::isCloseRequested());

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}