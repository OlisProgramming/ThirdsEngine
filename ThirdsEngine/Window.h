#pragma once

#include <SDL.h>

namespace te {
	// The window class handles many SDL functions.
	// It is also responsible for calling SDL_Init
	// and SDL_Quit.
	class Window {
	public:
		Window(const int w, const int h);
		~Window();

		// Returns whether creation was successful.
		bool show();

		void render();

	private:
		const int w;
		const int h;

		SDL_Window* sdlWnd;
		SDL_Surface* sdlScreenSurface;
	};
}