#pragma once
#include<iostream>
#include<chrono>
#include "SortingAlgorithms.h"

void swap(int &a, int &b);
void heapify(int* &arr, int n, int i, long long &comparisonCount);
long long heapSort(int* &arr, int n);

