#include "GameOverUIPanel.h"
#include "GameScreen.h"

bool GameScreen::m_GameOver;

GameOverUIPanel::GameOverUIPanel(Vector2i res) :UIPanel(
	res,
	(res.x / 10) * 2, // Start 2/10 accross
	res.y / 3, // 1/3 of the resolution from the top
	(res.x / 10) * 6, // as wide as 6/10 of the resolution
	res.y / 3, // and as tall as 1/3 of the resolution
	0, 255, 255, 255) {
	m_ButtonWidth = res.x / 5;
	m_ButtonHeight = res.y / 20;
	m_ButtonPadding = res.x / 100;

	m_Text.setFillColor(sf::Color(100, 0, 255, 255));
	m_Text.setString("GAME OVER!");

	m_Font.loadFromFile("font/LittleMageFont.ttf");
	m_Text.setFont(m_Font);

	m_Text.setPosition(Vector2f(m_ButtonWidth-m_ButtonPadding, (m_ButtonPadding) + m_ButtonHeight));

	m_Text.setCharacterSize(60);

	initialiseButtons();
}

void GameOverUIPanel::initialiseButtons() {
	addButton(m_ButtonWidth, m_ButtonHeight*3, m_ButtonWidth, m_ButtonHeight, 0, 255, 0, "Continue?");
	addButton(m_ButtonWidth, m_ButtonHeight*4 + m_ButtonPadding, m_ButtonWidth, m_ButtonHeight, 255, 0, 0, "Title Screen");
}

void GameOverUIPanel::draw(RenderWindow& window) {
	if (GameScreen::m_GameOver) {
		show();
		UIPanel::draw(window);
		window.draw(m_Text);
	}
	else {
		hide();
	}
}