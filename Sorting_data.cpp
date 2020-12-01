#include "Sorting_data.h"
#include <algorithm>





void insertion_sort(std::vector<int>* vector)
{
	int key;
	int compareindex;
	for (int keyindex = 1; keyindex < vector->size(); keyindex++)
	{
		key = (*vector)[keyindex];
		compareindex = keyindex - 1;
		while (compareindex >= 0 && key < (*vector)[compareindex])
		{
			(*vector)[compareindex+1] = (*vector)[compareindex];
			compareindex--;

		}
		(*vector)[compareindex+1] = key;

	}
}

void selection_sort(std::vector<int>* vector)
{
	int min_index;
	int compareindex;
	for (int i = 0; i < vector->size() - 1; i++)
	{
		min_index = i;
		for (compareindex = i+1; compareindex < vector->size(); compareindex++)
		{
			if ((*vector)[compareindex] < (*vector)[min_index])
			{
				min_index = compareindex;
			}
		}
		std::swap((*vector)[i],(*vector)[min_index]);
	}
}

void quicksort(std::vector<int>::iterator first, std::vector<int>::iterator last)
{

TailRecurse:

	auto const N = std::distance(first, last);
	if (N > 1)
	{
		auto pivot = last - 1;
		auto middel = partition(first, last, pivot);
		if (middel < first + (last - first) / 2)
		{
			quicksort(first, middel);
			first = middel + 1;
			goto TailRecurse;
		}
		else
		{
			quicksort(middel + 1, last);
			last = middel;
			goto TailRecurse;
		}

	}
	
}

void quicksort(int* first, int* last)
{
TailRecurse:


	if (first != last)
	{
		auto pivot = last - 1;
		auto middel = partition(first, last, pivot);
		if (middel < first + (last - first) / 2)
		{
			quicksort(first, middel);
			first = middel + 1;
			goto TailRecurse;
		}
		else
		{
			quicksort(middel + 1, last);
			last = middel;
			goto TailRecurse;
		}

	}
}

void quicksort_mot(std::vector<int>::iterator first, std::vector<int>::iterator last)
{

TailRecurse:

	auto const N = std::distance(first, last);
	if (N > 1)
	{
		auto pivot = midian_of_three(first,last-1);
		auto middel = partition(first, last, pivot);
		if (middel < first + (last - first) / 2)
		{
			quicksort(first, middel);
			first = middel + 1;
			goto TailRecurse;
		}
		else
		{
			quicksort(middel + 1, last);
			last = middel;
			goto TailRecurse;
		}

	}
	
}

std::vector<int>::iterator partition(std::vector<int>::iterator first, std::vector<int>::iterator last, std::vector<int>::iterator pivot)
{
	
	last--;
	while (true)
	{
		while (*first < *pivot && first < last)
		{
			first++;
		}
		while (*last >= *pivot && first < last)
		{
			last--;
		}
		std::swap(*first, *last);
		if (first >= last)
		{
			std::swap(*first, *pivot);
			return first;
		}
	}

}

int* partition(int* first, int* last, int* pivot)
{
	last--;
	while (true)
	{
		while (*first < *pivot && first < last)
		{
			first++;
		}
		while (*last >= *pivot && first < last)
		{
			last--;
		}
		std::swap(*first, *last);
		if (first >= last)
		{
			std::swap(*first, *pivot);
			return first;
		}
	}
}

std::vector<int>::iterator midian_of_three(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	auto mid = first + (last - first) / 2;
	if (*first > *last && *first < *mid || *first > *mid && *first < *last)
	{
		std::swap(*first, *last);
	}
	else if (*last > *first && *last < *mid || *last > *mid && *last < *first)
	{

	}
	else
	{
		std::swap(*mid, *last);
	}

	return last;
}

