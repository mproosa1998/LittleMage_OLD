#include "StartUIPanel.h"
#include <iostream>

StartUIPanel::StartUIPanel(Vector2i res) : UIPanel(
	res,
	(res.x / 10) * 2, // Start 2/10 accross
	res.y / 5, // 1/3 of the resolution from the top
	(res.x / 10) * 6, // as wide as 6/10 of the resolution
	res.y / 2, // and as tall as 1/3 of the resolution
	0, 255, 255, 255){
	m_ButtonWidth = res.x / 5;
	m_ButtonHeight = res.y / 20;
	m_ButtonPadding = res.x / 100;

	m_Text.setFillColor(sf::Color(100, 0, 255, 255));
	m_Text.setString("Little Mage");
	m_Font.loadFromFile("font/LittleMageFont.ttf");
	m_Text.setFont(m_Font);

	m_Text.setPosition(Vector2f(m_ButtonPadding, m_ButtonPadding ));

	m_Text.setCharacterSize(160);

	initialiseButtons();
}

void StartUIPanel::initialiseButtons() {
	addButton(m_ButtonPadding + m_ButtonWidth, m_ButtonHeight*5, m_ButtonWidth, m_ButtonHeight, 0, 255, 0, "New Game");
	addButton(m_ButtonPadding + m_ButtonWidth, ((m_ButtonHeight * 6) + m_ButtonPadding), m_ButtonWidth, m_ButtonHeight, 255, 0, 0, "Quit");
}

void StartUIPanel::draw(RenderWindow& window) {
	show();
	UIPanel::draw(window);
	window.draw(m_Text);
}