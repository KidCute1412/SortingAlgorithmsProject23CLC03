#include "BubbleSort.h"

using namespace std; 

long bubbleSort(int* arr, int n) {
    long comparisonCount = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisonCount++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return comparisonCount;
} 

void sortingAlgorithm::performBubbleSort(){
    auto start = std::chrono::high_resolution_clock::now();
  	BubbleSort(arr, n, comparison);
    auto end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration<double>(end - start).count();
}
