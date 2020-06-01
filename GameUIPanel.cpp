#include "GameUIPanel.h"
#include "WorldState.h"
#include <sstream>

int WorldState::HEALTH;

GameUIPanel::GameUIPanel(Vector2i res) : UIPanel(res, 1, 1, res.x / 3, res.y / 12, 100, 255, 255, 255) {
	m_Text.setFillColor(sf::Color(0, 255, 0, 255));
	m_Text.setString("Health: 3");
	m_Font.loadFromFile("font/LittleMageFont.ttf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(Vector2f(15, 15));
	m_Text.setCharacterSize(60);
}

void GameUIPanel::draw(RenderWindow& window) {
	UIPanel::draw(window);

	std::stringstream ss;
	ss << "Health: " << WorldState::HEALTH;
	m_Text.setString(ss.str());

	window.draw(m_Text);
}
