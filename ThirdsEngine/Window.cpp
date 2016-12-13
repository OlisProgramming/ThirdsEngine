#include "Window.h"

#include <stdio.h>
#include <GL/glew.h>

#define WINDOW_TITLE "Thirds Engine | Version 1.0"

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

		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		
		// Create window
		sdlWnd = SDL_CreateWindow(
			WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			w, h,
			SDL_WINDOW_OPENGL);

		if (sdlWnd == NULL) {
			fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}

		return true;
	}

	void Window::render() {

		SDL_GL_SwapWindow(sdlWnd);
	}
}