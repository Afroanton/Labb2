#pragma once
#include <vector>
/**
* creates a set of random values
* @param size of data set 
* @return Vector with generated values
*/
std::vector<int> random_data(int size);

/**
* creates a set of resing values
* @param size of data set
* @return Vector with generated values
*/
std::vector<int> rising_data(int size);

/**
* creates a set of decreasing values
* @param size of data set
* @return Vector with generated values
*/
std::vector<int> decreasing_data(int size);

/**
* creates a set of constant values
* @param size of data set
* @return Vector with generated values
*/
std::vector<int> constant_data(int size);
