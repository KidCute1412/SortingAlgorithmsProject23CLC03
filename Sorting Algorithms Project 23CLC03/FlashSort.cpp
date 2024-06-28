#include "FlashSort.h"








void FlashSort(int*& arr, int n, long long &comparison) {
    if (++comparison && n <= 1) return;

    // Step 1: Find the minimum and maximum values
    int minVal = arr[0];
    int maxIndex = 0;
    for (int i = 1;++comparison && i < n; ++i) {
        if (++comparison && arr[i] < minVal) minVal = arr[i];
        if (++comparison && arr[i] > arr[maxIndex]) maxIndex = i;
    }
    int maxVal = arr[maxIndex];

    // If all elements are the same
    if (++comparison && minVal == maxVal) return;

    

    // Number of classes
    int m = std::max(1, int(0.45 * n)); // Ensure at least one class

    // Allocate memory for class map
    int* classMap = new int [m](); // Initialize with zero

    double bucket = (m - 1) * 1.0 / (maxVal - minVal);
    // Step 2: Count elements per class
    for (int i = 0;++comparison && i < n; ++i) {
        int classIndex = int(bucket * (arr[i] - minVal));
        ++classMap[classIndex];
    }

    // Step 3: Transform class counts to positions
    for (int i = 1;++comparison && i < m; ++i) {
        classMap[i] += classMap[i - 1];
    }

    // Permute elements
  
    std::swap(arr[maxIndex], arr[0]);

    int move = 0;
    int flash;
    int j = 0;
    int k = m - 1;

    while (++comparison && move < n - 1) {
        while (++comparison && j > classMap[k] - 1) {
            ++j;
            k = static_cast<int>(bucket * (arr[j] - minVal));
        }
        if (++comparison && k < 0) break;
        flash = arr[j];
        while (++comparison && j != classMap[k]) {
            k = static_cast<int>(bucket * (flash - minVal));
            --classMap[k];
            swap(flash, arr[classMap[k]]);
            ++move;
        }
    }


    // Insertion sort within each class
    for (int k = 0;++comparison && k < m; ++k) {
        int start = classMap[k];
        int end = (++comparison && k == m - 1) ? n : classMap[k + 1];
        for (int i = start + 1;++comparison && i < end; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (++comparison && j >= start && ++comparison && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

    // Clean up allocated memory
    delete[] classMap;
}




void sortingAlgorithm::performFlashSort()
{
    auto start = std::chrono::high_resolution_clock::now();
    FlashSort(arr, n, comparison);
    auto end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double>(end - start).count();
}




