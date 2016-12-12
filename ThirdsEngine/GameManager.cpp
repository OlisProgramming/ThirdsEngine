#include "GameManager.h"

#include <stdio.h>
#include <GL/glew.h>

#include "Time.h"

#define FRAME_CAP (60.0)
#define NANOS_PER_FRAME (16666667)

namespace te {

	GameManager* GameManager::manager = nullptr;

	GameManager::GameManager() :
		wnd(nullptr), running(true), eventHandler(new EventHandler) {}

	GameManager::~GameManager() {
		delete eventHandler;
		delete wnd;
	}

	void GameManager::run() {

		manager = this;

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

		Timer timer;

		while (running) {

			while (timer.nanos_elapsed() > NANOS_PER_FRAME) {
				timer.add_nanos(NANOS_PER_FRAME);

				// TIME DEPENDENT CODE
				handleEvents();
			}

			// TIME INDEPENDENT CODE
			render();
		}
		
		// END MAIN LOOP
	}

	void GameManager::handleEvents() {
		eventHandler->update();
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {

			switch (e.type) {
			case SDL_QUIT:
				eventHandler->close();
				break;
			}
		}
	}

	void GameManager::render() {
		wnd->render();
	}

	void GameManager::update() {

	}

	void GameManager::requestClose() {
		running = false;
	}

	void GameManager::setWindow(Window* wnd) {
		this->wnd = wnd;
	}

	Window* GameManager::getWindow() const {
		return wnd;
	}
}