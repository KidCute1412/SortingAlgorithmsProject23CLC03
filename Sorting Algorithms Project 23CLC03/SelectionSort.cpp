#include "SelectionSort.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int*& arr, int n, long long& comparison) {
    for (int i = 0; ++comparison && i < n - 1; ++i) {
        // At this point, arr[0..i-1] is sorted, and its
        // entries are smaller than those in arr[i..n-1].
        int minIdx = i;
        // Select the smallest entry in arr[i..n-1]
        for (int j = i + 1; ++comparison && j < n; ++j) {
            if (++comparison && arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the smallest entry, arr[minIdx], with arr[i]
        swap(arr[minIdx], arr[i]);
    }
}

void sortingAlgorithm::performSelectionSort()
{

    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(arr, n, comparison);
    auto end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double, std::milli>(end - start).count();
}