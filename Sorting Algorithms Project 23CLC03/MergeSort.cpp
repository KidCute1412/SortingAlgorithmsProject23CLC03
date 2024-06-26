#include "MergeSort.h"
#include <chrono>
void sortingAlgorithm::performMergeSort(){
    auto start = std::chrono::high_resolution_clock::now();
    MergeSort(arr, 0, n - 1, comparison);
    auto finish = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double>(finish - start).count();
}

void Merge(int *&arr, int left, int mid, int right, long long& comp){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0;++comp && i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0;++comp && j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    while (++comp && i < n1 && ++comp && j < n2) {
        if (++comp && L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        
        k++;
    }
    while (++comp && i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (++comp && j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void MergeSort(int* &arr, int left, int right, long long& comp){
    if (++comp && left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid, comp);
    MergeSort(arr, mid + 1, right, comp);
    Merge(arr, left, mid, right, comp);
}
