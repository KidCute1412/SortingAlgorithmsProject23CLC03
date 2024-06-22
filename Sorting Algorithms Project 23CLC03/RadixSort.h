#pragma once
#include<iostream>
#include<chrono>






struct RadixSortAlgorithm
{
	int* arr = nullptr;
	int n = 0;
	long long comparison = 0;
	std::chrono::duration<double> time;
	std::chrono::high_resolution_clock::time_point start, end;
	int* positive = nullptr, * negative = nullptr;
	int n1 = 0, n2 = 0;
	void specifySign();
	void mergePosNegNum();
	void RadixSort();
	void performAlgorithm();
	~RadixSortAlgorithm();
};
