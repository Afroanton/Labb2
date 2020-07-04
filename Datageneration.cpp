#include "Datageneration.h"
#include <ctime>
#include <algorithm>
std::vector<int>* random_data(int size)
{
	std::vector<int>* random_values = new std::vector<int>;
	std::srand(std::time(nullptr));
	int value; 
	
	for (int i = 0; i < size; i++)
	{
		value = std::rand()%100;
		random_values->push_back(value);
	}
	return random_values;
	
}

std::vector<int>* rising_data(int size)
{
	std::vector<int>* rising_values = random_data(size);
	std::sort(rising_values->begin(), rising_values->end());
	return rising_values;

	
}

std::vector<int>* decreasing_data(int size)
{
	std::vector<int>* rising_values = random_data(size);
	std::sort(rising_values->begin(), rising_values->end(), std::greater<int>());
	return rising_values;
}

std::vector<int>* constant_data(int size)
{
	std::vector<int>* constant_values = new std::vector<int>;;
	int value = std::rand() % 10;
	std::srand(std::time(nullptr));
	for (int i = 0; i < size; i++)
	{
		constant_values->push_back(value);
	}
	return constant_values;
}
