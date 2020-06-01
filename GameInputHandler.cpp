#include "GameInputHandler.h"
#include "GameScreen.h"
//#include "SoundEngine.h"

void GameInputHandler::initialize() {
}

void GameInputHandler::handleKeyPressed(Event& event, RenderWindow& window) {
	if (event.key.code == Keyboard::Escape) {
		//SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->SwitchScreens("Start");
	}
}

void GameInputHandler::handleKeyReleased(Event& event, RenderWindow& window) {
}