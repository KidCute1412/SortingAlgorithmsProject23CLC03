#include "CountingSort.h"
#include "SortingAlgorithms.h"



void countingSort(int*& arr, int n, long long& comparison) 
{
    if (n == 0) return; // Handle empty array case

    // Find the maximum value in the input array manually
    int maxValue = arr[0];
    for (int i = 1; ++comparison && i < n; ++i) {
        if (++comparison && arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    int u = maxValue; // Use maxValue as the maximum value u

    int* f = new int[u + 1]{0}; // Perform distribution counting
    for (int i = 0; ++comparison && i < n; i++) {
        f[arr[i]]++;
    }

    for (int i = 1; ++comparison && i <= u; i++) { // Accumulate sum of frequencies
        f[i] = f[i - 1] + f[i];
    }

    int* b = new int[n]; // Distribute values to their final positions
    for (int i = n - 1; ++comparison && i >= 0; i--) {
        b[f[arr[i]] - 1] = arr[i];
        f[arr[i]]--;
    }

    for (int i = 0; ++comparison && i < n; i++) {
        arr[i] = b[i];
    }

    // Clean up
    delete[] f;
    delete[] b;
}

void sortingAlgorithm::performCountingSort()
{
    int* positive = nullptr, * negative = nullptr;
    int n1 = 0, n2 = 0;
    auto start = std::chrono::high_resolution_clock::now();
    specifySign(arr, n, positive, n1, negative, n2, comparison);
    if (n1 > 0) {
        int* temp = positive;
        countingSort(temp, n1, comparison); // Sort the positive array
    }
    if (n2 > 0) {
        int* temp = negative;
        countingSort(temp, n2, comparison); // Sort the negative array
    }
    mergePosNegNum(arr, n, positive, n1, negative, n2, comparison);
    auto end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}