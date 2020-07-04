#pragma once
#include <vector>
#include <algorithm>    // min_element, iter_swap, 
// upper_bound, rotate, 
// partition, 
// inplace_merge,
// make_heap, sort_heap, push_heap, pop_heap,
// is_heap, is_sorted
#include <cassert>      // assert 
#include <functional>   // less
#include <iterator>     // distance, begin, end, next

/// @brief sorting a vector with insertion sort
/// @param vector
void insertion_sort(std::vector<int>* vector);
std::vector<int>::iterator larger_then_pivot(std::vector<int>::iterator left_it, std::vector<int>::iterator right_it, std::vector<int>::iterator pivot);
std::vector<int>::iterator smaller_then_pivot(std::vector<int>::iterator left_it, std::vector<int>::iterator right_it, std::vector<int>::iterator pivot);



template<class FwdIt, class Compare = std::less<>>
void selection_sort1(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    for (auto it = first; it != last; ++it) {
        auto const selection = std::min_element(it, last, cmp);
        std::iter_swap(selection, it);
        assert(std::is_sorted(first, std::next(it), cmp));
    }
}

template<class FwdIt, class Compare = std::less<>>
void quick_sort1(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    auto const N = std::distance(first, last);
    if (N <= 1) return;
    auto const pivot = *std::next(first, N / 2);
    auto const middle1 = std::partition(first, last, [=](auto const& elem) {
        return cmp(elem, pivot);
        });
    auto const middle2 = std::partition(middle1, last, [=](auto const& elem) {
        return !cmp(pivot, elem);
        });
    quick_sort1(first, middle1, cmp); // assert(std::is_sorted(first, middle1, cmp));
    quick_sort1(middle2, last, cmp);  // assert(std::is_sorted(middle2, last, cmp));
}

/// @brief sorting a vector with selection sort
/// @param vector 
void selection_sort(std::vector<int>* vector);

/// @brief sorting a vector using quick sort
/// @param first iterator to the first element of the vector
/// @param last iterator to the element following the last element
void quicksort(std::vector<int>::iterator first, std::vector<int>::iterator last);

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

/// @brief used to find the median of 3 elements.
/// @param first iterator to the first element of the vector
/// @param last iterator to the last element of the vector
/// @return iterator to median element
std::vector<int>::iterator midian_of_three(std::vector<int>::iterator first, std::vector<int>::iterator last);

#include <algorithm>

