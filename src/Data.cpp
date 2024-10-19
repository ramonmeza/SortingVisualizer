#include "Data.hpp"

Data::Data(float value, float width, sf::Vector2f position)
{
	// Set value
	mValue = value;

	// Setup box
	mBox.setSize(sf::Vector2f(width, value));
	mBox.setPosition(position);
	mBox.setFillColor(COLOR_DEFAULT);
}

void Data::Select() { setColor(COLOR_SELECTED); }
void Data::Deselect() { setColor(COLOR_DEFAULT); }
void Data::Highlight() { setColor(COLOR_HIGHLIGHT); }

void Data::setColor(sf::Color color) { mBox.setFillColor(color); }
void Data::setPosition(sf::Vector2f position) { mBox.setPosition(position); }

float Data::getValue() { return mValue; }
sf::Vector2f Data::getPosition() { return mBox.getPosition(); }

void Data::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mBox);
}