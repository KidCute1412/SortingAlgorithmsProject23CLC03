#pragma once
#include<iostream>
#include<chrono>



void specifySign(int* arr, int n, int*& positive, int& n1, int*& negative, int& n2, long long& comparison);
void mergePosNegNum(int*& arr, int n, int*& positive, int n1, int*& negative, int n2, long long& comparison);
void countingSort(int*& arr, int n, long long& comparison);
