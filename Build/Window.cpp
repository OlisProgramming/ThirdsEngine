#include "Window.h"

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include "RenderUtil.h"

extern GLFWwindow* glfwWindow;

bool Window::createWindow(int width, int height, char* title)
{
	// Initialise GLFW
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (glfwWindow == NULL) {
		fprintf(stderr, "Failed to open GLFW window.");
		getchar();
		glfwTerminate();
		return false;
	}

	// Get desktop resolution
	const GLFWvidmode* vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	// Centre window on screen
	glfwSetWindowPos(glfwWindow, (vidMode->width - width) / 2, (vidMode->height - height) / 2);
	glfwMakeContextCurrent(glfwWindow);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW.");
		getchar();
		glfwTerminate();
		return false;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(glfwWindow, GLFW_STICKY_KEYS, GL_TRUE);

	return true;
}

void Window::render()
{
	RenderUtil::cls();

	// Drawing start



	// Drawing end

	// Swap buffers
	glfwSwapBuffers(glfwWindow);
	glfwPollEvents();
}

bool Window::isCloseRequested()
{
	return (glfwGetKey(glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS
		|| glfwWindowShouldClose(glfwWindow) != 0);
}

int Window::getWidth()
{
	int width = 0;
	int height = 0;
	glfwGetWindowSize(glfwWindow, &width, &height);
	return width;
}

int Window::getHeight()
{
	int width = 0;
	int height = 0;
	glfwGetWindowSize(glfwWindow, &width, &height);
	return height;
}

void Window::setSize(int width, int height)
{
	glfwSetWindowSize(glfwWindow, width, height);
}

void Window::setWidth(int width)
{
	setSize(width, glfwGetVideoMode(glfwGetPrimaryMonitor())->height);
}

void Window::setHeight(int height)
{
	setSize(glfwGetVideoMode(glfwGetPrimaryMonitor())->width, height);
}

void Window::setTitle(char* title)
{
	glfwSetWindowTitle(glfwWindow, title);
}

void Window::dispose()
{
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}