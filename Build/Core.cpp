#include "Core.h"

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include "Window.h"
#include "Input.h"
#include "Time.h"

bool isRunning;

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
int FRAME_CAP = 60;
GLFWwindow* glfwWindow;

Game game = Game();

Core::Core()
{
	isRunning = false;
}

Core::~Core()
{
}

void Core::start()
{
	if (isRunning) return;
	isRunning = true;

	auto lastTime = Time::getTime();
	float unprocessedTime = 0;
	const float frameTime = 1.0f / FRAME_CAP;
	int frames = 0;
	float frameCounter = 0.0f;

	if (!Window::createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Thirds Engine | Version 0.1")) {
		return;
	}

	// Set colour to clear screen with
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	do {
		bool shouldRender = false;

		auto startTime = Time::getTime();
		auto passedTime = startTime - lastTime;
		lastTime = startTime;

		std::chrono::duration<float> passedTimeSeconds = passedTime;
		unprocessedTime += passedTimeSeconds.count();
		frameCounter += passedTimeSeconds.count();

		while (unprocessedTime > frameTime)
		{
			shouldRender = true;

			unprocessedTime -= frameTime;

			// Update game
			Time::setDelta(frameTime);
			Input::update();
			game.input();
			game.update();

			if (frameCounter > 1) {
				printf("%i FPS\n", frames);
				frames = 0;
				frameCounter = 0.0f;
			}
		}

		if (shouldRender) {
			render();
			frames++;
		}

		if (Window::isCloseRequested())
			stop();
		
	} while (isRunning);
}

void Core::update()
{
}

void Core::render()
{
	Window::render();
	game.render();
}

void Core::stop()
{
	isRunning = false;
	dispose();
}

void Core::dispose()
{
	Window::dispose();
}