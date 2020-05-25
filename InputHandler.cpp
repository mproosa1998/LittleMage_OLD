#include <sstream>
#include "InputHandler.h"

using namespace sf;
using namespace std;

void InputHandler::initialiseInputHandler(
	ScreenManagerRemoteControl* sw, vector<shared_ptr<Button>> buttons,
	View* pointerToUIView, Screen* parentScreen) {

	m_ScreenManagerRemoteControl = sw;
	m_Buttons = buttons;
	m_PointerToUIPanelView = pointerToUIView;
	m_ParentScreen = parentScreen;
}

void InputHandler::handleInput(RenderWindow& window, Event& event) {
	if (event.type == Event::KeyPressed) {
		handleKeyPressed(event, window);
	}
	if (event.type == Event::KeyReleased) {
		handleKeyReleased(event, window);
	}

	if (event.type == Event::MouseButtonReleased) {
		auto end = m_Buttons.end();

		for (auto i = m_Buttons.begin(); i != end; ++i) {
			if ((*i)->m_Collider.contains(window.mapPixelToCoords(Mouse::getPosition(), (*getPointerToUIView())))) {
				handleLeftClick((*i)->m_Text, window);
				break;
			}
		}
	}
}

void InputHandler::handleKeyPressed(Event& event, RenderWindow& window) {}//Do nothing unless handled by a derived class
void InputHandler::handleKeyReleased(Event& event, RenderWindow& window) {}
void InputHandler::handleLeftClick(string& buttonInteractedWith, RenderWindow& window) {}

View* InputHandler::getPointerToUIView() {
	return m_PointerToUIPanelView;
}

ScreenManagerRemoteControl* InputHandler::getPointerToScreenManagerControl() {
	return m_ScreenManagerRemoteControl;
}

Screen* InputHandler::getmParentScreen() {
	return m_ParentScreen;
}