#pragma once

#include "Window.h"

namespace te {
	class GameManager {
	public:
		GameManager();
		~GameManager();

		// Runs the game.
		void run();

		void setWindow(Window* wnd);
		Window* getWindow() const;

	private:
		Window* wnd;
	};
}