#include "RadixSort.h"



void RadixSortAlgorithm::specifySign()
{
	int countNegative = 0;
	for (int i = 0; ++comparison && i < n; i++)
	{
		if (++comparison && arr[i] < 0)
		{
			countNegative++;
		}
	}

	n1 = n - countNegative;
	n2 = countNegative;
	if (n1 != 0)
	{
		positive = new int[n1];
	}
	if (n2 != 0)
	{
		negative = new int[n2];
	}

	int pos1 = 0, pos2 = 0;
	for (int i = 0; ++comparison && i < n; i++)
	{
		if (++comparison && arr[i] < 0)
		{
			negative[pos2++] = -arr[i];
		}
		else {
			positive[pos1++] = arr[i];
		}

	}
}
void RadixSortAlgorithm::mergePosNegNum()
{
	int pos1 = 0, pos2 = n2 - 1;
	for (int i = 0; ++comparison && i < n; i++)
	{
		if (++comparison && pos2 >= 0)
		{
			arr[i] = -negative[pos2--];
		}
		else {
			arr[i] = positive[pos1++];
		}
	}
}
void RadixSortAlgorithm::RadixSort()
{
	if (!arr)
	{
		return;
	}

	// find max value
	int max = arr[0];
	for (int i = 0; ++comparison && i < n; i++)
	{
		if (++comparison && arr[i] > max)
		{
			max = arr[i];
		}
	}
	// find number of digits
	int digits = (int)log10(max) + 1;
	// create buckets
	int** buckets = new int* [10];
	for (int i = 0; ++comparison && i < 10; i++)
	{
		buckets[i] = new int[n];
	}
	// Sort Algorithm
	int* countArr = new int[10];

	int exp = 1;
	for (int i = 0; ++comparison && i < digits; i++)
	{

		for (int j = 0; ++comparison && j < 10; j++)
		{
			countArr[j] = 0;
		}
		// form groups
		for (int j = 0; ++comparison && j < n; j++)
		{
			int idx = (arr[j] / exp) % 10;
			buckets[idx][countArr[idx]++] = arr[j];
		}
		// collect elements
		int pos = 0;
		for (int j = 0; ++comparison && j < 10; j++)
		{
			for (int k = 0; ++comparison && k < countArr[j]; k++)
			{
				arr[pos++] = buckets[j][k];
			}
		}
		exp *= 10;
	}
	delete[] countArr;
	for (int i = 0; ++comparison && i < 10; i++)
	{
		delete[] buckets[i];
	}
	delete[] buckets;

}
void RadixSortAlgorithm::performAlgorithm()
{
	start = std::chrono::high_resolution_clock::now();
	specifySign();
	if (n1 > 0)
		RadixSort();
	if (n2 > 0)
		RadixSort();
	mergePosNegNum();
	end = std::chrono::high_resolution_clock::now();
	time = end - start;
}
RadixSortAlgorithm::~RadixSortAlgorithm()
{
	if (arr)
	{
		delete[] arr;
	}
	if (positive)
	{
		delete[] positive;
	}
	if (negative)
	{
		delete[] negative;
	}
}