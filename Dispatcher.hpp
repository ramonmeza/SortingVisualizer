#pragma once

#include <iostream>
#include <random>
#include <vector>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "BubbleSort.hpp"

class BubbleSort;
class Data;

class Dispatcher : public sf::Drawable {
public:
	Dispatcher(int NumberOfElements = 100, int WindowWidth = 1280, int WindowHeight = 720);

	// Bubble sort variables
	float SortUpdateCounter;
	float SortUpdateRate;

	void Bubble(float dt);

	BubbleSort* SortAlg;

private:
	std::vector<Data*> Objects;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};