#include "ShakerSort.h"

void sortingAlgorithm::performShakerSort(){
    auto start = std::chrono::high_resolution_clock::now();
    ShakerSort(arr, n, comparison);
    auto finish = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration<double, std::milli>(finish - start).count();
}

void ShakerSort(int *&a, int n, long long& comp){
	int left = 0;
	int right = n - 1;
	int k = 0;
	while (++comp && left < right){
		for (int i = left;++comp && i < right; i++){
			if (++comp && a[i] > a[i + 1]){
				std::swap(a[i], a[i + 1]);
				k = i;
			}
			
		}
		right = k;
		for (int i = right;++comp && i > left; i--){
			if (++comp && a[i] < a[i - 1]){
				std::swap(a[i], a[i - 1]);
				k = i;
			}
			
		}
		left = k;
	}
}
