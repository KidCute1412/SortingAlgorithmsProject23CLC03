#pragma once
#include<iostream>
#include<chrono>
#include "SortingAlgorithms.h"

void swap(int &a, int &b);
long heapify(int* arr, int n, int i, long &comparisonCount);
long heapSort(int* arr, int n);
void sortingAlgorithm::performHeapSort();
