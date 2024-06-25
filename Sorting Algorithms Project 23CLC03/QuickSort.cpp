#include "QuickSort.h"

void sortingAlgorithm::performQuickSort(){
    auto start = std::chrono::high_resolution_clock::now();
    QuickSortMedian(arr, 0, n, comparison);
    auto finish = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration<double>(finish - start).count();
}

void QuickSortMedian(int *a, int start, int last, long long& comp){
    if (last-start<2) return;
    int med = MedianOfThreePartition(a,start,last,comp);
    QuickSortMedian(a,start,med,comp);
    QuickSortMedian(a,med,last,comp);
}

int MedianOfThreePartition(int *a, int start, int last, long long& comp){
    int x = a[start], y = a[(last-start)/2+start], z = a[last-1],i = start-1, j = last;
    if ((y>x && y<z) || (y>z && y<x)) x=y;
    else if ((z>x && z<y) || (z>y && z<x)) x=z;
    comp+=3;
    while (i < j) {
        do {j--; comp++;}
        while (a[j] > x);
        do {i++; comp++;}
        while (a[i] < x);
        if (i < j) std::swap(a[i],a[j]);
        else return j+1;
    }
}
