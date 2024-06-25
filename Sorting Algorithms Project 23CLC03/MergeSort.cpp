#include "MergeSort.h"

void sortingAlgorithm::performMergeSort(){
    auto start = std::chrono::high_resolution_clock::now();
    MergeSort(arr, 0, n - 1, comparison);
    auto finish = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double>(finish - start).count();
}

void Merge(int *arr, int left, int mid, int right, long long& comp){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        comp++;
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int* arr, int left, int right, long long& comp){
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid, comp);
    MergeSort(arr, mid + 1, right, comp);
    Merge(arr, left, mid, right, comp);
}
