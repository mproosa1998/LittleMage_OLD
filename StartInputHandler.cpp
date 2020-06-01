#include "StartInputHandler.h"
//#include "SoundEngine.h"
#include "WorldState.h"
#include <iostream>

int WorldState::LEVEL_NUMBER;

void StartInputHandler::handleKeyPressed(Event& event, RenderWindow& window) {
	// Quit
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
}

void StartInputHandler::handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window) {
	if (buttonInteractedWith == "New Game"){
		//SoundEngine::playClick();
		WorldState::LEVEL_NUMBER = 0;
		getPointerToScreenManagerRemoteControl()->LoadLevelInPlayMode("level1");
	}
	if (buttonInteractedWith == "Quit") {
		//SoundEngine::playClick();
		window.close();
	}
}