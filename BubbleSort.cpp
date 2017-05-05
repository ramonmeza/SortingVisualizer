#include "BubbleSort.hpp"

#include <iostream>

BubbleSort::BubbleSort(int NumberOfElements)
{
	SortCurrentStep = 0;
	SortCurrentIndex = 0;
	SortMaxIndex = NumberOfElements;
	isSorted = false;
}

void BubbleSort::Sort(std::vector<Data*>& Objects)
{
	// Decide which step to perform
	switch (SortCurrentStep)
	{
	case 0:
		// Step 0
		//Select current item
		Objects[SortCurrentIndex]->Select();

		// Increment step
		SortCurrentStep++;
		break;
	case 1:
		// Step 1
		// Check if last position
		if (SortCurrentIndex < (SortMaxIndex - 1))
		{
			// Highlight next data object to be compared
			Objects[SortCurrentIndex + 1]->Highlight();
		}

		// Increment step
		SortCurrentStep++;
		break;
	case 2:
		// Step 2
		// Check if last position
		if (SortCurrentIndex == (SortMaxIndex - 1))
		{
			// Change color to completed
			Objects[SortCurrentIndex]->setColor(COLOR_SORTED);

			// Shrink the search area
			SortMaxIndex--;

			// Begin search again
			SortCurrentIndex = 0;
			SortCurrentStep = 0;

			break;
		}

		// If the current is greater than the next
		if (Objects[SortCurrentIndex]->getValue() > Objects[SortCurrentIndex + 1]->getValue())
		{
			// Swap the two objects' positions
			sf::Vector2f position = Objects[SortCurrentIndex]->getPosition();
			Objects[SortCurrentIndex]->setPosition(Objects[SortCurrentIndex + 1]->getPosition());
			Objects[SortCurrentIndex + 1]->setPosition(position);

			// Swap the objects in the vector
			Data* temp = Objects[SortCurrentIndex];
			Objects[SortCurrentIndex] = Objects[SortCurrentIndex + 1];
			Objects[SortCurrentIndex + 1] = temp;
			temp = nullptr;

			// Increment the current index to continue sorting
			SortCurrentIndex++;

			// Increment step
			SortCurrentStep++;

			break;
		}

		// If the current is less than the next
		// Deselect current
		Objects[SortCurrentIndex]->Deselect();

		// Change current index to next
		SortCurrentIndex++;

		// Go back to Step 0
		SortCurrentStep = 0;

		break;
	case 3:
		// Step 3
		// Deselect last element
		if (SortCurrentIndex > 0)
			Objects[SortCurrentIndex - 1]->Deselect();

		// Loop to Step 0
		SortCurrentStep = 0;
		break;
	}

	// Check if sorting is completed
	if (SortMaxIndex < 1) {
		// Change color of last element
		Objects[SortCurrentIndex]->setColor(COLOR_SORTED);

		// Set isSorted to true to stop running this code
		isSorted = true;

		// Debug message to make sure it worked!
		std::cout << "Sorted!" << std::endl;
	}
}