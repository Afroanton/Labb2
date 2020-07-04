#include "time.h"
#include <fstream>
#include <algorithm>
#include <string>

void time_all(std::vector<int>(*generate_data_funk)(int size),int start,int end)
{
	int measurement_points = 6;
	int distans = (end - start) / measurement_points;
	for (int N = start; N <= end; N += distans)
	{
		auto data = generate_data_funk(N);
		time_insertin_sort(data);
	}
	

}

void time_insertion_sort(std::vector<int>* container)
{
	std::string save_data = "insertion_sort.data";
	std::cout << "insertion_sort: " << "\n" << "N        T(s)" << "\n";
	auto unsorted = *container;
	auto sort_funk = [](std::vector<int>* random) {insertion_sort(random); };
	time(sort_funk, &unsorted);
}
void time_selection_sort(std::vector<int>*(*generate_data_funk)(int size), int start, int end)
{
	std::string save_data = "selection_sort.data";
	std::cout << "selection_sort: " << "\n" << "N        T(s)" << "\n";;
	auto sort_funk = [](std::vector<int>* random) {selection_sort(random); };
	time_intervall(sort_funk, generate_data_funk, start, end, save_data);
}
void time_quicksort(std::vector<int>*(*generate_data_funk)(int size), int start, int end)
{
	std::string save_data = "quicksort.data";
	std::cout << "quicksort: " << "\n" << "N        T(s)" << "\n";;
	auto sort_funk = [](std::vector<int>* random) {quicksort(random->begin(),random->end()); };
	time_intervall(sort_funk, generate_data_funk, start, end, save_data);
}
void time_quicksort_mot(std::vector<int>*(*generate_data_funk)(int size), int start, int end)
{
	std::string save_data = "quicksort_mot.data";
	std::cout << "quicksort_mot: " << "\n" << "N        T(s)" << "\n";;
	auto sort_funk = [](std::vector<int>* random) {quicksort_mot(random->begin(), random->end()); };
	time_intervall(sort_funk, generate_data_funk, start, end, save_data);
}
void time_std_sort(std::vector<int>*(*generate_data_funk)(int size), int start, int end)
{
	std::string save_data = "std_sort.data";
	std::cout << "std_sort: " << "\n" << "N        T(s)" << "\n";;
	auto sort_funk = [](std::vector<int>* random) {std::sort(random->begin(), random->end()); };
	time_intervall(sort_funk, generate_data_funk, start, end, save_data);
	
}
std::chrono::duration<double> time(void(*sort)(std::vector<int>*), std::vector<int>* container)
{
	int samples = 5;
	std::chrono::duration<double> time(0);
	
	for (int i = 0; i < samples; i++)
	{
		std::vector<int>* container1 = container;
		auto start = std::chrono::steady_clock::now();
		sort(container);
		auto end = std::chrono::steady_clock::now();
		time += (end - start) / samples;
	}

	std::cout << container->size() << "     " << time.count() << "\n";
	return time;
}

void time_intervall(void(*sort_funk)(std::vector<int>*), std::vector<int>* (*generate_data_funk)(int size),int start,int end,std::string save_data)
{
	std::ofstream file;
	file.open(save_data);
	int measurement_points = 6;
	int distans = (end - start) / measurement_points;
	for (int N = start; N <= end; N += distans)
	{
		std::vector<int>* container = generate_data_funk(N);
		std::chrono::duration<double> t = time(sort_funk, container);
		delete container;
		file << N << "     " << t.count() << std::endl;

	}
	file.close();
}

