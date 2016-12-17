#pragma once

#include <GL/glew.h>

#include "EventHandler.h"
#include "Window.h"

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

		// Render the game. This runs as fast as possible.
		void render(GLuint shader);

		// Update the game. This runs at 60Hz.
		void update();

		Window* wnd;
		EventHandler* eventHandler;
		bool running;
	};
}