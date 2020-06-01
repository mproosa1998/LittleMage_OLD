#pragma once
#include "InputHandler.h"

class StartInputHandler : public InputHandler {
public:
	void handleKeyPressed(Event& event, RenderWindow& window) override;
	void handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window) override;
};