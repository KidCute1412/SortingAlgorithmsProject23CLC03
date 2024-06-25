#include "ShellSort.h"

long shellSort(int* arr, int n) {
    long comparisonCount = 0;

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                comparisonCount++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }

    return comparisonCount;
} 

void sortingAlgorithm::performShellSort(){
    auto start = std::chrono::high_resolution_clock::now();
  	ShellSort(arr, n, comparison);
    auto end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration<double>(end - start).count();
}
