#include "GameScreen.h"
#include "GameUIPanel.h"
#include "GameInputHandler.h"
#include "GameOverUIPanel.h"
#include "WorldState.h"

int WorldState::WORLD_HEIGHT;
int WorldState::NUM_ENEMIES_AT_START;
int WorldState::NUM_ENEMIES;

GameScreen::GameScreen(ScreenManagerRemoteControl* smrc, Vector2i res) {
	m_GIH = make_shared<GameInputHandler>();
	auto guip = make_unique<GameUIPanel>(res);
	addPanel(move(guip), smrc, m_GIH);

	auto m_GOIH = make_shared<GameOverInputHandler>();
	auto gouip = make_unique<GameOverUIPanel>(res);
	addPanel(move(gouip), smrc, m_GOIH);

	m_ScreenManagerRemoteControl = smrc;
	float screenRatio = VideoMode::getDesktopMode().width / VideoMode::getDesktopMode().height;

	WorldState::WORLD_HEIGHT = WorldState::WORLD_WIDTH / screenRatio;

	m_View.setSize(WorldState::WORLD_WIDTH, WorldState::WORLD_HEIGHT);

	m_View.setCenter(Vector2f(WorldState::WORLD_WIDTH / 2, WorldState::WORLD_HEIGHT / 2));

	m_BackgroundTexture.loadFromFile("graphics/littlemagebackground.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	auto textureSize = m_BackgroundSprite.getTexture()->getSize();
	m_BackgroundSprite.setScale(float(m_View.getSize().x) / textureSize.x, float(m_View.getSize().y) / textureSize.y);
}

void GameScreen::initialise() {
	m_GIH->initialize();

	WorldState::NUM_ENEMIES = 0;

	m_GameOver = false;
	if (WorldState::LEVEL_NUMBER == 0) {
		WorldState::NUM_ENEMIES_AT_START = WorldState::NUM_ENEMIES;
		WorldState::LEVEL_NUMBER = 1;
		WorldState::HEALTH = 0;
	}
}

void GameScreen::update(float fps) {
	Screen::update(fps);

	if (!m_GameOver) {
		if (WorldState::NUM_ENEMIES <= 0) {
			WorldState::LEVEL_NUMBER++;
			m_ScreenManagerRemoteControl->LoadLevelInPlayMode("level1");
		}
		//if (WorldState::HEALTH <= 0) {
		if(true){
			m_GameOver = true;
		}
	}
}

void GameScreen::draw(RenderWindow& window) {
	window.setView(m_View);
	window.draw(m_BackgroundSprite);
	Screen::draw(window);
}
