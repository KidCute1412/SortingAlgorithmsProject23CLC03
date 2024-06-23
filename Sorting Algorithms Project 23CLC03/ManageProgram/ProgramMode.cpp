#include "ProgramMode.h"
#include<string>
using namespace std;

SortingAlgorithms getSortingAlgorithm(const std::string& str) {
	if (str == "selection-sort") return SortingAlgorithms::SelectionSort;
	if (str == "insertion-sort") return SortingAlgorithms::InsertionSort;
	if (str == "bubble-sort") return SortingAlgorithms::BubbleSort;
	if (str == "shaker-sort") return SortingAlgorithms::ShakerSort;
	if (str == "shell-sort") return SortingAlgorithms::ShellSort;
	if (str == "heap-sort") return SortingAlgorithms::HeapSort;
	if (str == "merge-sort") return SortingAlgorithms::MergeSort;
	if (str == "quick-sort") return SortingAlgorithms::QuickSort;
	if (str == "counting-sort") return SortingAlgorithms::CountingSort;
	if (str == "radix-sort") return SortingAlgorithms::RadixSort;
	if (str == "flash-sort") return SortingAlgorithms::FlashSort;
	return SortingAlgorithms::NONE;
}

InputOrder getInputOrder(const std::string& str)
{
	if (str == "'rand") return InputOrder::rand;
	if (str == "-nsorted") return InputOrder::nsorted;
	if (str == "-sorted") return InputOrder::sorted;
	if (str == "-rev") return InputOrder::rev;
	return InputOrder::NONE;
}


OutputParameters getOutputParameters(const std::string& str)
{
	if (str == "-time") return OutputParameters::time;
	if (str == "-comp") return OutputParameters::comp;
	if (str == "-both") return OutputParameters::both;
	return OutputParameters::NONE;
}


void generateData(sortingAlgorithm &data, InputOrder order)
{
	switch (order)
	{
	case InputOrder::rand:
		generateRandomData(data.arr, data.n);
		break;
	case InputOrder::nsorted:
		generateNearlySortedData(data.arr, data.n);
		break;
	case InputOrder::sorted:
		generateSortedData(data.arr, data.n);
		break;
	case InputOrder::rev:
		generateReverseSortedData(data.arr, data.n);
		break;
	default:
		break;
	}
}

void performSortingAlgorithms(sortingAlgorithm& data, SortingAlgorithms algo)
{
    switch (algo)
    {
    case SortingAlgorithms::SelectionSort:
        data.performSelectionSort();
        break;
    case SortingAlgorithms::InsertionSort:
		data.performInsertionSort();
		break;
	case SortingAlgorithms::BubbleSort:
		data.performBubbleSort();
		break;
	case SortingAlgorithms::ShakerSort:
		data.performShakerSort();
		break;
	case SortingAlgorithms::ShellSort:
		data.performShellSort();
		break;
	case SortingAlgorithms::HeapSort:
		data.performHeapSort();
		break;
	case SortingAlgorithms::MergeSort:
		data.performMergeSort();
		break;
	case SortingAlgorithms::QuickSort:
		data.performQuickSort();
		break;
	case SortingAlgorithms::CountingSort:
		data.performCountingSort();
		break;
	case SortingAlgorithms::RadixSort:
		data.performRadixSort();
		break;
	case SortingAlgorithms::FlashSort:
		data.performFlashSort();
		break;
	default:
		break;
    }
}


bool checkNumber(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}








void processCommandLine(int argc, char* argv[]) {
    if (argc <= 4) {
        std::cerr << "Invalid number of arguments." << std::endl;
        return;
    }

    std::string command = argv[1];

    if (command == "-a") {
        SortingAlgorithms algo = getSortingAlgorithm(argv[2]);
		sortingAlgorithm data;
		// Command line 1
        if (argc == 5 && !checkNumber((string)argv[3])) { // Case: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
			
            std::string inputFile = argv[3];
            OutputParameters outputParam = getOutputParameters(argv[4]);
			readFileData(data.arr, data.n, inputFile);
			performSortingAlgorithms(data, algo);
			// Output Operations
			//
			//
			if (data.arr)
			{
				delete [] data.arr;
			}

        }
		// Command line 2
        else if (argc == 6) { // Case: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
            int inputSize = std::stoi(argv[3]);
			if (inputSize <= 0)
				return;
			data.n = inputSize;
            InputOrder inputOrder = getInputOrder(argv[4]);
            OutputParameters outputParam = getOutputParameters(argv[5]);

			generateData(data, inputOrder);
            performSortingAlgorithms(data, algo);
			// Output Operations
			//
			//
            if (data.arr)
			{
				delete [] data.arr;
			}

            
        }
		// Command line 3
        else if (argc == 5) { // Case: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
            int inputSize = std::stoi(argv[3]);
			if (inputSize <= 0)
				return;
            OutputParameters outputParam = getOutputParameters(argv[4]);
			sortingAlgorithm data1, data2, data3, data4;
			data1.n = inputSize, data2.n = inputSize, data3.n = inputSize, data4.n = inputSize;
			InputOrder inputOrder = InputOrder::rand;
			generateData(data1, inputOrder);
			inputOrder = InputOrder::nsorted;
			generateData(data2, inputOrder);
			inputOrder = InputOrder::sorted;
			generateData(data3, inputOrder);
			inputOrder = InputOrder::rev;
			generateData(data4, inputOrder);
			performSortingAlgorithms(data1, algo);
			performSortingAlgorithms(data2, algo);
			performSortingAlgorithms(data3, algo);
			performSortingAlgorithms(data4, algo);

            // Output Operations
			//
			//
			delete[] data1.arr;
			delete[] data2.arr;
			delete[] data3.arr;
			delete[] data4.arr;



            
        }
        else {
            std::cerr << "Invalid number of arguments for -a command." << std::endl;
        }
    }
    else if (command == "-c") {
        SortingAlgorithms algo1 = getSortingAlgorithm(argv[2]);
        SortingAlgorithms algo2 = getSortingAlgorithm(argv[3]);
		sortingAlgorithm data1, data2;
		// Command line 4
        if (argc == 5) { // Case: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
            std::string inputFile = argv[4];
			readFileData(data1.arr, data2.n, inputFile);
			copyArray(data1.arr, data2.arr, data1.n);
			performSortingAlgorithms(data1, algo1);
			performSortingAlgorithms(data2, algo2);
			// Output Operations
			// 
			//
			if (data1.arr)
				delete[] data1.arr;
			if (data2.arr)
				delete[] data2.arr;

        }
		// Command line 5
        else if (argc == 6) { // Case: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
            int inputSize = std::stoi(argv[4]);
			if (inputSize <= 0)
				return;
            InputOrder inputOrder = getInputOrder(argv[5]);

			data1.n = inputSize, data2.n = inputSize;
			generateData(data1, inputOrder);
			copyArray(data1.arr, data2.arr, data1.n);
			performSortingAlgorithms(data1, algo1);
			performSortingAlgorithms(data2, algo2);
			// Output Operations

			if (data1.arr)
				delete[] data1.arr;
			if (data2.arr)
				delete[] data2.arr;
            
        }
        else {
            std::cerr << "Invalid number of arguments for -c command." << std::endl;
        }
    }
    else {
        std::cerr << "Invalid command." << std::endl;
    }
}