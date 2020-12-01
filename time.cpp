#include "time.h"
#include <cmath>
#include <algorithm>
#include <string>

void time_all(std::vector<int>*(*generate_data_funk)(int size),int start, int end)
{
	std::string save_data1 = "insertion_sort.data";
	std::string save_data2 = "selection_sort.data";
	std::string save_data3 = "quicksort.data";
	std::string save_data4 = "quicksort_mot.data";
	std::string save_data5 = "std_sort.data";
	auto sort_funk1 = [](std::vector<int>* random) {insertion_sort(random); };
	auto sort_funk2 = [](std::vector<int>* random) {selection_sort(random); };
	auto sort_funk3 = [](std::vector<int>* random) {quicksort(random->begin(), random->end()); };
	auto sort_funk4 = [](std::vector<int>* random) {quicksort_mot(random->begin(), random->end()); };
	auto sort_funk5 = [](std::vector<int>* random) {std::sort(random->begin(), random->end()); };
	
	for (int N = start; N <= end; N+=1000)
	{
		auto container = generate_data_funk(N);
		time_calculation(sort_funk1, container, save_data1);
		time_calculation(sort_funk2, container, save_data2);
		time_calculation(sort_funk3, container, save_data3);
		time_calculation(sort_funk4, container, save_data4);
		time_calculation(sort_funk5, container, save_data5);
	
		delete container;
	}
	
	
}

void time_calculation(void(*sort_funk)(std::vector<int>*),std::vector<int>* container,std::string save_data)
{
	std::ofstream file;
	file.open(save_data,std::ios::app);

	double measurement_points = 5;
	double sqrt_time = 0;
	double sum_time = 0;
	double mean_time;
	double s;
	
	for (int i = 0; i < measurement_points; i++)
	{
		auto current_time = time(sort_funk, container);
		sum_time += current_time;
		sqrt_time += pow(current_time, 2);
	}
	mean_time = sum_time / measurement_points;
	s = sqrt((sqrt_time - (measurement_points * pow(mean_time, 2))) / (measurement_points - 1));
	

		
	
	file << container->size() << " " << mean_time << " " << s << "\n";
	file.close();

}

float time(void(*sort)(std::vector<int>*), std::vector<int>* container)
{
	
	std::chrono::duration<double> time(0);
	auto copy_container = *container;

	auto start = std::chrono::steady_clock::now();
	sort(&copy_container);
	auto end = std::chrono::steady_clock::now();
	time += (end - start);

	/*
	* if (std::is_sorted(copy_container.begin(), copy_container.end()))
	{
		std::cout << "sorted!" << "\n";
	}
	*/
	
	return time.count();
}

