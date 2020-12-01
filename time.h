#pragma once
#include <chrono>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Datageneration.h"
#include "Sorting_data.h"

void time_all(std::vector<int>*(*generate_data_funk)(int size), int start, int end);

void time_calculation(void(*sort_funk)(std::vector<int>*), std::vector<int>* container, std::string save_data);

//void time_selection_sort(std::vector<int>* container);

//void time_quicksort(std::vector<int>* container);

//void time_quicksort_mot(std::vector<int>* container);

//void time_std_sort(std::vector<int>* container);

float time(void(*sort)(std::vector<int>*), std::vector<int>* container);

//void time_intervall(void(*sort)(std::vector<int>*), std::vector<int>* (*generate_data_funk)(int size),int start,int end,std::string save_data);
