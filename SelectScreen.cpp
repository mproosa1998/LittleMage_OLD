#include "SelectScreen.h"
#include "StartUIPanel.h"
#include "StartInputHandler.h"

SelectScreen::SelectScreen(
	ScreenManagerRemoteControl* smrc, Vector2i res) {
	auto suip = make_unique<StartUIPanel>(res);
	auto sih = make_shared<StartInputHandler>();
	addPanel(move(suip), smrc, sih);
	m_ScreenManagerRemoteControl = smrc;

	m_BackgroundTexture.loadFromFile("graphics/littlemagebackground.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	auto textureSize = m_BackgroundSprite.getTexture()->getSize();
	m_BackgroundSprite.setScale(float(m_View.getSize().x) / textureSize.x,
		float(m_View.getSize().y) / textureSize.y);
}

void SelectScreen::draw(RenderWindow& window) {
	window.setView(m_View);
	window.draw(m_BackgroundSprite);

	Screen::draw(window);
}