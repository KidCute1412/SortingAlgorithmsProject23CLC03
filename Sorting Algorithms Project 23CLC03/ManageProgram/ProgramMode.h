#pragma once

#include <string>
#include "../ManageProgram/DataGenerator.h"
#include "../SortingAlgorithms.h"
#include <iostream>
#include "OutputData.h"


using namespace std;
enum class SortingAlgorithms {
	SelectionSort,
	InsertionSort,
	BubbleSort,
	ShakerSort,
	ShellSort,
	HeapSort,
	MergeSort,
	QuickSort,
	CountingSort,
	RadixSort,
	FlashSort,
	NONE
};

enum class InputOrder {
	rand,
	nsorted,
	sorted,
	rev,
	FILE,
	NONE
};

enum class OutputParameters {
	time,
	comp,
	both,
	NONE
};




std::string toString(SortingAlgorithms algo);
SortingAlgorithms getSortingAlgorithm(const string& str);
InputOrder getInputOrder(const string& str);
OutputParameters getOutputParameters(const string& str);

void performSortingAlgorithms(sortingAlgorithm& data, SortingAlgorithms algo);

void generateData(sortingAlgorithm& data, InputOrder order);
void processCommandLine(int argc, char* argv[]);
bool checkNumber(string str);







