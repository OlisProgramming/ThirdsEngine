#include "EventHandler.h"

#include <SDL.h>

#include "GameManager.h"

namespace te {

	EventHandler::EventHandler() {
		keyState = SDL_GetKeyboardState(NULL);
	}

	void EventHandler::close() {
		GameManager::manager->requestClose();
	}

	bool EventHandler::getKey(Key keycode) {
		return keyState[keycode];
	}
}