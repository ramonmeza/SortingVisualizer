#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 720

#include <iostream>
#include <random>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Dispatcher.hpp"

int main(int argc, char* argv[])
{
	// Window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bubble Sort Visualization");
	sf::Clock DeltaClock;
	float DeltaTime = 0.f;

	Dispatcher algs(100, WINDOW_WIDTH, WINDOW_HEIGHT);

	// Window loop
	while (window.isOpen())
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		algs.Bubble(DeltaTime);

		// Draw
		window.clear();

		window.draw(algs);

		window.display();

		// Calculate DeltaTime
		DeltaTime = DeltaClock.restart().asSeconds();

	}
}