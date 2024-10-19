#include "Dispatcher.hpp"

Dispatcher::Dispatcher(int NumberOfElements, int WindowWidth, int WindowHeight)
{
	// Random number generator
	int maxRand = NumberOfElements; // Max Y value is the height of the window
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(10, WindowHeight);

	// Calculate width of object
	float ElementWidth = (float) (WindowWidth / NumberOfElements);

	// Populate vector of data objects with random values
	for (int i = 0; i < NumberOfElements; i++)
	{
		Objects.push_back(new Data((float)distribution(generator), ElementWidth, sf::Vector2f((ElementWidth * i), 0.f)));
	}

	// Bubble sort variables
	SortUpdateCounter = 0.f;
	SortUpdateRate = 0.000001f;
	SortAlg = nullptr;
}

void Dispatcher::Bubble(float dt)
{
	if (SortAlg == nullptr)
		SortAlg = new BubbleSort(Objects.size());

	if (SortAlg != nullptr)
	{
		// Update logic
		if (SortUpdateCounter >= SortUpdateRate && !SortAlg->isSorted)
		{
			// Reset counter
			SortUpdateCounter = 0.f;

			SortAlg->Sort(Objects);
		}

		// Increment counter
		SortUpdateCounter += dt;
	}
}

void Dispatcher::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Draw the data objects
	for (Data* x : Objects)
	{
		target.draw(*x);
	}
}