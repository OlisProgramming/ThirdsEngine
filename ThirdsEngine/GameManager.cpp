#include "GameManager.h"

#include <stdio.h>
#include <GL/glew.h>

namespace te {
	GameManager::GameManager() :
		wnd(nullptr) {}

	GameManager::~GameManager() {
	}

	void GameManager::run() {

		if (wnd == nullptr) {
			fprintf(stderr, "GameManager::run\nWindow* wnd was not initialised with a call to GameManager::setWindow(Window* wnd).");
			return;
		}

		if (!wnd->show()) return;

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		// Because this does not return a pointer, the GL Context must be created here
		SDL_GLContext glContext = SDL_GL_CreateContext(wnd->getSdlWnd());
		wnd->setGlContext(&glContext);

		glewExperimental = GL_TRUE;
		glewInit();

		// BEGIN MAIN LOOP
		
		wnd->render();
		
		// END MAIN LOOP

		delete wnd;
	}

	void GameManager::setWindow(Window* wnd) {
		this->wnd = wnd;
	}

	Window* GameManager::getWindow() const {
		return wnd;
	}
}