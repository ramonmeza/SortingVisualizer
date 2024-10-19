#pragma once

#define COLOR_DEFAULT	sf::Color::Red
#define COLOR_SELECTED	sf::Color::Blue
#define COLOR_HIGHLIGHT	sf::Color::Cyan
#define COLOR_SORTED	sf::Color::Green

#include <SFML/Graphics/RectangleShape.hpp>

#include "Dispatcher.hpp"

// Class for holding data
class Data : public sf::Drawable {
public:
	Data(float value = 0, float width = 0.f, sf::Vector2f position = sf::Vector2f(0.f, 0.f));

	// Helper functions
	void Select();
	void Deselect();
	void Highlight();

	void setColor(sf::Color color);
	void setPosition(sf::Vector2f position);

	float getValue();
	sf::Vector2f getPosition();

private:
	float mValue;
	sf::RectangleShape mBox;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};