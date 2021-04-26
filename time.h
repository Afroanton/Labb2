#pragma once
#include <chrono>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Datageneration.h"
#include "Sorting_data.h"

void time_all(std::vector<int>*(*generate_data_funk)(int size), int start, int end);

void time_calculation(void(*sort_funk)(std::vector<int>*), std::vector<int>* container, std::string save_data);

float time(void(*sort)(std::vector<int>*), std::vector<int>* container);

