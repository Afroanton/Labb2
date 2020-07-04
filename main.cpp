#include "time.h"
#include <string>
void print(std::vector<int> test)
{
	for (auto v : test)
	{
		std::cout << v << " ";
	}
	std::cout << "\n";
}
void print_file(std::string filename)
{
	std::ifstream file;
	file.open(filename);
	std::string content;
	std::cout << filename << "\n" << "N      T(s)      S" << "\n";
	while (!file.eof())
	{
		std::getline(file, content);
		std::cout << content << "\n";
	}
	file.close();
}
int main()
{
	
	
	auto random = [](int N) {std::vector<int>* data = random_data(N); return data;};
	auto rising = [](int N) {std::vector<int>* data = rising_data(N); return data; };
	auto decreasing = [](int N) {std::vector<int>* data = decreasing_data(N); return data; };
	auto constant = [](int N) {std::vector<int>* data = constant_data(N); return data; };
	auto sort_funk3 = [](std::vector<int>* random) {quicksort(random->begin(), random->end()); };
	int start = 1000;
	int end = 10000;

	/*
	auto test = decreasing(10);
	std::vector<int> test2 = {12,13,50,63,64,76};
	print(*test);
	quicksort_mot(test->begin(),test->end());
	print(*test);
	*/

	
	time_all(random, start,end);
	print_file("insertion_sort.data");
	print_file("selection_sort.data");
	print_file("quicksort.data");
	print_file("quicksort_mot.data");
	print_file("std_sort.data");

	//"gnuplot code" plot "insertion_sort.data" w lp lc 1,"selection_sort.data" w lp lc 2,"quicksort.data" w lp lc 3, "quicksort_mot.data" w lp lc 4 , "std_sort.data" w lp lc 5
	

}