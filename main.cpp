#include <iostream>
#include "Datageneration.h"
void print(std::vector<int> test)
{
	for (auto i : test)
	{
		std::cout << i << std::endl;
	}
}
int main()
{
	
	std::vector<int> test = random_data(5);
	std::vector<int> test2 = rising_data(5);
	std::vector<int> test3 = decreasing_data(5);
	std::vector<int> test4 = constant_data(5);
	print(test3);
}