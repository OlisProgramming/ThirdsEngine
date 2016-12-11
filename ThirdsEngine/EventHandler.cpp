#include "EventHandler.h"

#include "GameManager.h"

namespace te {

	void EventHandler::close() {
		GameManager::manager->requestClose();
	}
}