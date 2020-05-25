#include "Button.h"

Button::Button(Vector2f position, float width, float height,
	int red, int green, int blue, string text) {
	m_Button.setPosition(position);
	m_Button.setFillColor(Color(red, green, blue));
	m_Button.setSize(Vector2f(width, height));

	m_Text = "" + text;

	float textPaddingX = width / 5;
	float textPaddingY = height / 5;
	m_ButtonText.setCharacterSize(height * .7f);
	m_ButtonText.setString(text);
	m_Font.loadFromFile("font/LittleMageFont.ttf");
	m_ButtonText.setPosition(Vector2f((position.x + textPaddingX), (position.y + textPaddingY)));

	m_Collider = FloatRect(position, Vector2f(width, height));
}

void Button::draw(RenderWindow& window) {
	window.draw(m_Button);
	window.draw(m_ButtonText);
}