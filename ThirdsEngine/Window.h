#pragma once

#include <SDL.h>

namespace te {
	class Window {
	public:
		Window(const int w, const int h);
		~Window();

		// Returns whether creation was successful.
		bool show();

		void render();

		inline SDL_Window* getSdlWnd() const { return sdlWnd; }
		inline void setGlContext(SDL_GLContext* ctx) { glContext = ctx; }


	private:
		const int w;
		const int h;

		SDL_Window* sdlWnd;
		SDL_GLContext* glContext;
	};
}