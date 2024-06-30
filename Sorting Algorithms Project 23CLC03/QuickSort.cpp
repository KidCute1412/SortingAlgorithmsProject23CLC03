#include "QuickSort.h"
#include <chrono>
void sortingAlgorithm::performQuickSort(){
    auto start = std::chrono::high_resolution_clock::now();
    QuickSortMedian(arr, 0, n, comparison);
    auto finish = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count();
}

void QuickSortMedian(int *&a, int start, int last, long long& comp){
    if (++comp && last-start<2) return;
    int med = MedianOfThreePartition(a,start,last,comp);
    QuickSortMedian(a,start,med,comp);
    QuickSortMedian(a,med,last,comp);
}

int MedianOfThreePartition(int *&a, int start, int last, long long& comp){
    int x = a[start], y = a[(last-start)/2+start], z = a[last-1],i = start-1, j = last;
    if ((++comp && y > x && ++comp && y < z) || (++comp && y > z && ++comp && y < x)) x=y;
    else if ((++comp && z > x && ++comp && z < y) || (++comp && z > y && ++comp && z < x)) x=z;
    comp += 3;
    while (++comp && i < j) {
        do {j--;}
        while (++comp && a[j] > x);
        do {i++;}
        while (++comp && a[i] < x);
        if (++comp && i < j) std::swap(a[i],a[j]);
        else return j + 1;
    }
}
