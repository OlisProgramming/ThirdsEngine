#include "Window.h"

#include <stdio.h>

namespace te {

	Window::Window(const int w, const int h) :
		w(w), h(h) {}

	Window::~Window() {
		// Wait two seconds
		SDL_Delay(2000);

		// Destroy window
		SDL_DestroyWindow(sdlWnd);

		// Quit SDL subsystems
		SDL_Quit();
	}

	bool Window::show() {

		sdlWnd = NULL;
		sdlScreenSurface = NULL;

		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		
		// Create window
		sdlWnd = SDL_CreateWindow(
			"Thirds Engine | Version 1.0",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			w, h,
			SDL_WINDOW_SHOWN);

		if (sdlWnd == NULL) {
			fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}

		// Get window surface
		sdlScreenSurface = SDL_GetWindowSurface(sdlWnd);

		return true;
	}

	void Window::render() {

		SDL_FillRect(sdlScreenSurface, NULL, SDL_MapRGB(sdlScreenSurface->format, 0xFF, 0xFF, 0xFF));
		SDL_UpdateWindowSurface(sdlWnd);
	}
}