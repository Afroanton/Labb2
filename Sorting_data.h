#pragma once
#include <vector>
#include <algorithm>    // min_element, iter_swap, 
#include <cassert>      // assert 
#include <functional>   // less
#include <iterator>     // distance, begin, end, next

/// @brief sorting a vector with insertion sort
/// @param vector
void insertion_sort(std::vector<int>* vector);


/// @brief sorting a vector with selection sort
/// @param vector 
void selection_sort(std::vector<int>* vector);


/// @brief sorting a vector using quicksort
/// @param first iterator to the first element of the vector
/// @param last iterator to the element following the last element
void quicksort(std::vector<int>::iterator first, std::vector<int>::iterator last);


/// @brief sorting a vector using quicksort
/// @param first pointer to the first element of the vector
/// @param last pointer to the element following the last element
void quicksort(int* first, int* last);


/// @brief sorting a vector using quick sort with median of three
/// @param first iterator to the first element of the vector
/// @param last iterator to the element following the last element
void quicksort_mot(std::vector<int>::iterator first, std::vector<int>::iterator last);


/// @brief funktion used by quicksort and quicksort_mot to partition the vector in such a was that all elements
/// @brief smaller then the pivot are placed to the left of it and all elements larger are placed to the right 
/// @param first iterator to the first element of the vector
/// @param last iterator to the element following the last element
/// @param pivot the element that will get sorted used by the outer elements to compare if it's larger or smaller
/// @return iterator to pivot element
std::vector<int>::iterator partition(std::vector<int>::iterator first, std::vector<int>::iterator last, std::vector<int>::iterator pivot);


/// @brief funktion used by quicksort and quicksort_mot to partition the vector in such a was that all elements
/// @brief smaller then the pivot are placed to the left of it and all elements larger are placed to the right 
/// @param first iterator to the first element of the vector
/// @param last iterator to the element following the last element
/// @param pivot the element that will get sorted used by the outer elements to compare if it's larger or smaller
/// @return iterator to pivot element
int* partition(int* first, int* last, int* pivot);


/// @brief used to find the median of 3 elements.
/// @param first iterator to the first element of the vector
/// @param last iterator to the last element of the vector
/// @return iterator to median element
std::vector<int>::iterator midian_of_three(std::vector<int>::iterator first, std::vector<int>::iterator last);


