#pragma once

#include <string>
#include "../ManageProgram/DataGenerator.h"
#include "../SortingAlgorithms.h"




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
	NONE
};

enum class OutputParameters {
	time,
	comp,
	both,
	NONE
};




SortingAlgorithms getSortingAlgorithm(const string& str);
InputOrder getInputOrder(const string& str);
OutputParameters getOutputParameters(const string& str);



void generateData(sortingAlgorithm& data, InputOrder order);
void processCommandLine(int argc, char* argv[]);
bool checkNumber(string str);







