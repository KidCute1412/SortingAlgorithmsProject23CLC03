#pragma once








struct sortingAlgorithm
{
	int* arr = nullptr;
	int n = 0;
	long long comparison = 0;
	double time = 0;
	
	void performSelectionSort();
	void performInsertionSort();
	void performBubbleSort();
	void performShakerSort();
	void performShellSort();
	void performHeapSort();
	void performMergeSort();
	void performQuickSort();
	void performCountingSort();
	void performRadixSort();
	void performFlashSort();

};

