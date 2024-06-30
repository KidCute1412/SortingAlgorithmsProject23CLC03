#include "HeapSort.h"

using namespace std;

//void swap(int &a, int &b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}

void heapify(int* &arr, int n, int i, long long &comparisonCount) {
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (++comparisonCount && left < n && ++comparisonCount && arr[left] > arr[largest])
        largest = left;

    if (++comparisonCount && right < n && ++comparisonCount && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest, comparisonCount);
    }
    
}

long long heapSort(int* &arr, int n) {
    long long comparisonCount = 0;

    for (int i = n / 2 - 1;++comparisonCount && i >= 0; i--) {
        heapify(arr, n, i, comparisonCount);
    }

    for (int i = n - 1;++comparisonCount && i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, comparisonCount);
    }

    return comparisonCount;
} 

void sortingAlgorithm::performHeapSort(){
    auto start = std::chrono::high_resolution_clock::now();
  	comparison = heapSort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
