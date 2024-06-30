#include "BubbleSort.h"

using namespace std; 

long long bubbleSort(int* &arr, int n) {
    long long comparisonCount = 0;
    bool swapped;
    for (int i = 0;++comparisonCount && i < n - 1; i++) {
        swapped = false;
        for (int j = 0; ++comparisonCount && j < n - i - 1; j++) {
            
            if (++comparisonCount && arr[j] > arr[j + 1]) {
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
  	comparison = bubbleSort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
