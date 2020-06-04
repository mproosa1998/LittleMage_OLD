#include "GameOverInputHandler.h"
//#include "SoundEngine.h"
#include "WorldState.h"
#include <iostream>

void GameOverInputHandler::handleKeyPressed(Event& event, RenderWindow& window) {
	if (event.key.code == Keyboard::Escape) {
		//SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->SwitchScreens("Start");
	}
}

void GameOverInputHandler::handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window) {
	if (buttonInteractedWith == "Continue?") {
		//SoundEngine::playClick();
		WorldState::LEVEL_NUMBER = 0;
		getPointerToScreenManagerRemoteControl()->LoadLevelInPlayMode("level1");
	}
	else if (buttonInteractedWith == "Title Screen") {
		//SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->SwitchScreens("Start");
	}
}