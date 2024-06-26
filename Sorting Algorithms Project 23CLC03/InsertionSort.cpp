#include "InsertionSort.h"



void insertionSort(int*& arr, int n, long long& comparison) {
    for (int i = 1;++comparison && i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (++comparison && j >= 0 && (++comparison && arr[j] > key)) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}


void sortingAlgorithm::performInsertionSort()
{
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(arr, n, comparison);
    auto end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration<double>(end - start).count();
}
