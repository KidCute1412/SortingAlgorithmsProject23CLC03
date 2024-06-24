#include "CountingSort.h"


void specifySign(int* arr, int n, int*& positive, int& n1, int*& negative, int& n2, long long& comparison) {
    int countNegative = 0;
    for (int i = 0; ++comparison && i < n; i++) {
        if (++comparison && arr[i] < 0) {
            countNegative++;
        }
    }

    n1 = n - countNegative;
    n2 = countNegative;
    if (n1 != 0) {
        positive = new int[n1];
        for (int i = 0, j = 0; i < n; ++i) {
            if (arr[i] >= 0) {
                positive[j++] = arr[i];
            }
        }
    }
    if (n2 != 0) {
        negative = new int[n2];
        for (int i = 0, j = 0; i < n; ++i) {
            if (arr[i] < 0) {
                negative[j++] = -arr[i];
            }
        }
    }
}

void mergePosNegNum(int*& arr, int n, int* positive, int n1, int* negative, int n2, long long& comparison) {
    int pos1 = 0, pos2 = n2 - 1;
    for (int i = 0; ++comparison && i < n; i++) {
        if (++comparison && pos2 >= 0) {
            arr[i] = -negative[pos2--];
        } else {
            arr[i] = positive[pos1++];
        }
    }
    if (positive) {
        delete[] positive;
    }
    if (negative) {
        delete[] negative;
    }
}

void countingSort(int* arr, int n, long long& comparison) 
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
	time = std::chrono::duration<double>(end - start).count();
}