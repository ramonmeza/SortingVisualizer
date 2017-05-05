#pragma once

#include "Data.hpp"

class Data;

class BubbleSort
{
public:
	BubbleSort(int NumberOfElements = 100);

	void Sort(std::vector<Data*>& Objects);

	bool isSorted;

private:
	int SortCurrentStep;
	int SortCurrentIndex;
	int SortMaxIndex;
};