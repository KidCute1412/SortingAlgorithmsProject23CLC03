#pragma once
#include<iostream>
#include<chrono>
#include<cmath>
#include "SortingAlgorithms.h"





struct sortingAlgorithm;
void specifySign(int * arr, int n, int*& positive, int& n1, int*& negative, int& n2, long long &comparison);
void mergePosNegNum(int*& arr, int n, int* positive, int n1, int* negative, int n2, long long &comparison);
void RadixSort(int*& arr, int n, long long& comparison);	

