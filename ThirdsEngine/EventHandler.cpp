#include "EventHandler.h"

#include <SDL.h>

#include "GameManager.h"

namespace te {

	EventHandler::EventHandler() {
		keyState = SDL_GetKeyboardState(NULL);
		mouse_x = new int;
		mouse_y = new int;
	}

	void EventHandler::update() {
		mouseState = SDL_GetMouseState(mouse_x, mouse_y);
	}

	void EventHandler::close() {
		GameManager::manager->requestClose();
	}

	bool EventHandler::getKey(const Key keycode) const {
		return keyState[keycode] != 0;
	}

	bool EventHandler::getMouse(const MouseButton mb) const {
		return (mouseState & SDL_BUTTON(mb)) != 0;
	}

	int EventHandler::getMouseX() const {
		return *mouse_x;
	}

	int EventHandler::getMouseY() const {
		return *mouse_y;
	}

	Vec2 EventHandler::getMousePos() const {
		Vec2 v;
		v.x = float(getMouseX());
		v.y = float(getMouseY());
		return v;
	}
}