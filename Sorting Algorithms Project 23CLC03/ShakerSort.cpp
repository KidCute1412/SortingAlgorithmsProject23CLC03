#include "ShakerSort.h"

void sortingAlgorithm::performShakerSort(){
    auto start = std::chrono::high_resolution_clock::now();
    ShakerSort(arr, n, comparison);
    auto finish = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double>(finish - start).count();
}

void ShakerSort(int *a, int n, long long& comp){
	int left = 0;
	int right = n - 1;
	int k = 0;
	while (left < right){
		for (int i = left; i < right; i++){
			if (a[i] > a[i + 1]){
				std::swap(a[i], a[i + 1]);
				k = i;
			}
			comp++;
		}
		right = k;
		for (int i = right; i > left; i--){
			if (a[i] < a[i - 1]){
				std::swap(a[i], a[i - 1]);
				k = i;
			}
			comp++;
		}
		left = k;
	}
}
