#pragma once
#include "UIPanel.h"

class StartUIPanel : public UIPanel {
private: 
	void initialiseButtons();
public:
	StartUIPanel(Vector2i red);
	void virtual draw(RenderWindow& window);
};