#include "GameEngine.h"

GameEngine::GameEngine() {
	m_Resolution.x = VideoMode::getDesktopMode().width;
	m_Resolution.y = VideoMode::getDesktopMode().height;
	m_Window.create(VideoMode(m_Resolution.x, m_Resolution.y), "Little Mage", Style::Titlebar);

	//SCREEN MANAGER
}

void GameEngine::run() {
	while (m_Window.isOpen()) {
		m_DT = m_Clock.restart();
		m_FPS = m_DT.asSeconds();
		handleInput();
		update();
		draw();
	}
}

void GameEngine::handleInput() {
	// SCREEN MANAGER
}

void GameEngine::update() {
	// SCREEN MANAGER
}

void GameEngine::draw() {
	m_Window.clear(Color::Black);
	// Screen Manager
	m_Window.display;
}