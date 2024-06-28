#include "ProgramMode.h"
#include<string>
using namespace std;

std::string toString(SortingAlgorithms algo) {
	switch (algo) {
	case SortingAlgorithms::SelectionSort: return "Selection Sort";
	case SortingAlgorithms::InsertionSort: return "Insertion Sort";
	case SortingAlgorithms::BubbleSort: return "Bubble Sort";
	case SortingAlgorithms::ShakerSort: return "Shaker Sort";
	case SortingAlgorithms::ShellSort: return "Shell Sort";
	case SortingAlgorithms::HeapSort: return "Heap Sort";
	case SortingAlgorithms::MergeSort: return "Merge Sort";
	case SortingAlgorithms::QuickSort: return "Quick Sort";
	case SortingAlgorithms::CountingSort: return "Counting Sort";
	case SortingAlgorithms::RadixSort: return "Radix Sort";
	case SortingAlgorithms::FlashSort: return "Flash Sort";
	case SortingAlgorithms::NONE: return "NONE";
	default: return "Unknown";
	}
}

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
	if (str == "-rand") return InputOrder::rand;
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
        SortingAlgorithms algo = getSortingAlgorithm((string)argv[2]);
		if (algo == SortingAlgorithms::NONE) {
			std::cerr << "Invalid algorithm." << std::endl;
			return;
		}
		sortingAlgorithm data;
		// Command line 1
        if (argc == 5 && !checkNumber((string)argv[3])) { // Case: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
			
            string fileName = argv[3];
			InputOrder inputOrder = InputOrder::FILE;
            OutputParameters outputParam = getOutputParameters(argv[4]);
			if (outputParam == OutputParameters::NONE) {
				std::cerr << "Invalid output parameter." << std::endl;
				return;
			}
			readFileData(data.arr, data.n, fileName);
			if (!data.arr) {
				std::cerr << "Invalid input file." << std::endl;
				return;
			}
			performSortingAlgorithms(data, algo);
			
			// Output Operations
			
			printAlgorithmMode12(data, algo, inputOrder, outputParam, fileName);
			outputSortedArray(data.arr, data.n);
			if (data.arr)
			{
				delete [] data.arr;
			}

        }
		// Command line 2
        else if (argc == 6) { // Case: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
			
			if (!checkNumber(argv[3]))
				return;
			int inputSize = stoi(argv[3]);
			if (inputSize <= 0)
				return;
			string fileName = "";
			data.n = inputSize;
            InputOrder inputOrder = getInputOrder((string)argv[4]);
            OutputParameters outputParam = getOutputParameters((string)argv[5]);

			if (inputOrder == InputOrder::NONE) {
				cerr << "Invalid input order." << endl;
				return;
			}
			if (outputParam == OutputParameters::NONE) {
				cerr << "Invalid output parameter." << endl;
				return;
			}
			
			generateData(data, inputOrder);
			outputGeneratedData(data.arr, data.n);
            performSortingAlgorithms(data, algo);

			// Output Operations

			printAlgorithmMode12(data, algo, inputOrder, outputParam, fileName);
			outputSortedArray(data.arr, data.n);
            if (data.arr)
			{
				delete [] data.arr;
			}

            
        }
		// Command line 3
        else if (argc == 5) { // Case: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
            if(!checkNumber(argv[3]))
				return;
			int inputSize = std::stoi(argv[3]);
			if (inputSize <= 0)
				return;
            OutputParameters outputParam = getOutputParameters(argv[4]);
			if (outputParam == OutputParameters::NONE) {
				cerr << "Invalid output parameter." << endl;
				return;
			}

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
			outputAllGeneratedData(data1.arr, data2.arr, data3.arr, data4.arr, inputSize);
			performSortingAlgorithms(data1, algo);
			performSortingAlgorithms(data2, algo);
			performSortingAlgorithms(data3, algo);
			performSortingAlgorithms(data4, algo);
			
            // Output Operations

			printAlgorithmMode3(data1, data2, data3, data4, algo, outputParam);
			
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
		if (algo1 == SortingAlgorithms::NONE || algo2 == SortingAlgorithms::NONE) {
			cerr << "Invalid algorithm." << endl;
			return;
		}
		sortingAlgorithm data1, data2;
		// Command line 4
        if (argc == 5) { // Case: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
            std::string fileName = argv[4];
			readFileData(data1.arr, data1.n, fileName);
			if (!data1.arr) {
				std::cerr << "Invalid input file." << std::endl;
				return;
			}
			copyArray(data1.arr, data2.arr, data1.n);
			data2.n = data1.n;
			
			performSortingAlgorithms(data1, algo1);
			performSortingAlgorithms(data2, algo2);
			// Output Operations
			
			printComparisonMode(data1, data2, algo1, algo2, InputOrder::FILE, fileName);
			
			if (data1.arr)
				delete[] data1.arr;
			if (data2.arr)
				delete[] data2.arr;

        }
		// Command line 5
        else if (argc == 6) { // Case: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
            if (!checkNumber(argv[4]))
				return;
			int inputSize = std::stoi(argv[4]);
			if (inputSize <= 0)
				return;
			string fileName = "";
            InputOrder inputOrder = getInputOrder(argv[5]);
			if (inputOrder == InputOrder::NONE) {
				cerr << "Invalid input order." << endl;
				return;
			}
			data1.n = inputSize, data2.n = inputSize;
			generateData(data1, inputOrder);
			copyArray(data1.arr, data2.arr, data1.n);
			data2.n = data1.n;
			outputGeneratedData(data1.arr, data1.n);
			performSortingAlgorithms(data1, algo1);
			performSortingAlgorithms(data2, algo2);
			// Output Operations

			printComparisonMode(data1, data2, algo1, algo2, inputOrder, fileName);
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