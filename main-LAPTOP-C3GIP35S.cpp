#include "time.h"
void print(std::vector<int> test)
{
	for (auto v : test)
	{
		std::cout << v << " ";
	}
	std::cout << "\n";
}

int main()
{
	
	auto random = [](int N) {std::vector<int>* data = random_data(N); return data;};
	auto rising = [](int N) {std::vector<int>* data = rising_data(N); return data; };
	auto decreasing = [](int N) {std::vector<int>* data = decreasing_data(N); return data; };
	auto constant = [](int N) {std::vector<int>* data = constant_data(N); return data; };
	auto sort_funk1 = [](std::vector<int>* random) {quicksort_mot(random->begin(), random->end()); };
	auto sort_funk2 = [](std::vector<int>* random) {selection_sort(random); };
	auto sort_funk3 = [](std::vector<int>* random) {insertion_sort(random); };
	auto sort_funk4 = [](std::vector<int>* random) {quick_sort1(random->begin(), random->end()); };

	int start = 5000;
	int end = 50000;
	
	
	auto container = random(10);


	
	
	
	

}