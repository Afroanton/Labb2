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



	auto sort_funk1 = [](std::vector<int>* random) {insertion_sort(random); };
	auto sort_funk2 = [](std::vector<int>* random) {selection_sort(random); };
	auto sort_funk3 = [](std::vector<int>* random) {quicksort(random->begin(), random->end()); };
	auto sort_funk4 = [](std::vector<int>* random) {quicksort_mot(random->begin(), random->end()); };
	auto sort_funk5 = [](std::vector<int>* random) {std::sort(random->begin(), random->end()); };
	auto sort_funk6 = [](std::vector<int>* random) {quicksort(&random->front(), &random->back()+1); };

	auto t = time(sort_funk3, rising(10000));
	auto t2 = time(sort_funk6, rising(10000));

	std::cout << t << std::endl;
	std::cout << t2 << std::endl;

	int start = 1000;
	int end = 10000;
	
	remove("insertion_sort.data");
	remove("selection_sort.data");
	remove("quicksort.data");
	remove("quicksort_mot.data");
	remove("std_sort.data");
	time_all(rising, start,end);
	print_file("insertion_sort.data");
	print_file("selection_sort.data");
	print_file("quicksort.data");
	print_file("quicksort_mot.data");
	print_file("std_sort.data");

	//"gnuplot code" plot "insertion_sort.data" w lp lc 1 ,"selection_sort.data" w lp lc 2,"quicksort.data" w lp lc 3, "quicksort_mot.data" w lp lc 4 , "std_sort.data" w lp lc 5
	
	/*
	set xrange[1000:10000]
	set yrange[0:0.6]
	f(x)=x... 
	fit f(x) ".data" via x
	
	
	*/
}