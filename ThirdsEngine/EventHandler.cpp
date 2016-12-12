#include "EventHandler.h"

#include <SDL.h>

#include "GameManager.h"

namespace te {

	EventHandler::EventHandler() {
		keyState = SDL_GetKeyboardState(NULL);
	}

	void EventHandler::update() {
		mouseState = SDL_GetMouseState(mouse_x, mouse_y);
	}

	void EventHandler::close() {
		GameManager::manager->requestClose();
	}

	bool EventHandler::getKey(Key keycode) {
		return keyState[keycode] != 0;
	}

	bool EventHandler::getMouse(MouseButton mb) {
		return (mouseState & SDL_BUTTON(mb)) != 0;
	}
}