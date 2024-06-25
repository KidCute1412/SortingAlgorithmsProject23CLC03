#include "HeapSort.h"

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

long heapify(int* arr, int n, int i, int &comparisonCount) {
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && ++comparisonCount && arr[left] > arr[largest])
        largest = left;

    if (right < n && ++comparisonCount && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest, comparisonCount);
    }
    return comparisonCount;
}

long heapSort(int* arr, int n) {
    long comparisonCount = 0;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisonCount);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisonCount);
    }

    return comparisonCount;
} 

void sortingAlgorithm::performHeapSort(){
    auto start = std::chrono::high_resolution_clock::now();
  	HeapSort(arr, n, comparison);
    auto end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration<double>(end - start).count();
}
