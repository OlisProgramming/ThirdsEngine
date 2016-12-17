#pragma once

#include <GL/glew.h>

#include "Camera.h"
#include "EventHandler.h"
#include "Window.h"
#include "Shader.h"
#include "RenderEngine.h"

namespace te {
	class GameManager {
	public:
		GameManager();
		~GameManager();
		static GameManager* manager;

		// Runs the game.
		void run();

		// Closes the game softly by breaking from main loop.
		void requestClose();

		void setWindow(Window* wnd);
		Window* getWindow() const;

	private:
		// Handle all events from SDL.
		void handleEvents();

		// Method for handling camera position.
		void handleCamera(render::Camera& cam);

		// Render the game. This runs as fast as possible.
		void render(render::RenderEngine& renderEngine, render::Camera& cam);

		// Update the game. This runs at 60Hz.
		void update();

		Window* wnd;
		EventHandler* eventHandler;
		bool running;

		render::Mesh* mesh;
	};
}