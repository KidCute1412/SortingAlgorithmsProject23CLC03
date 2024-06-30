#include "ShellSort.h"

long shellSort(int* &arr, int n) {
    long comparisonCount = 0;

    for (int gap = n / 2;++comparisonCount && gap > 0; gap /= 2) {
        for (int i = gap;++comparisonCount && i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i;++comparisonCount && j >= gap; j -= gap) {
                comparisonCount++;
                if (++comparisonCount && arr[j - gap] > temp) {
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
  	comparison = shellSort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double, std::milli>(end - start).count();
}
