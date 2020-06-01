#pragma once
#include "InputHandler.h"

class GameScreen;

class GameInputHandler : public InputHandler {
public:
	void initialize();
	void handleKeyPressed(Event& event, RenderWindow& window) override;
	void handleKeyReleased(Event& event, RenderWindow& window) override;
};

