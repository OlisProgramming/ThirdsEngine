#include "GameManager.h"

#include <stdio.h>

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