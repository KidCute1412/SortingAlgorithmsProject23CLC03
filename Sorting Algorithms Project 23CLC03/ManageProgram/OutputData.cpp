#include "OutputData.h"
#include "ProgramMode.h"







void printAlgorithmMode12(sortingAlgorithm data, SortingAlgorithms algorithm, InputOrder input, OutputParameters output, string fileName)
{
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << toString(algorithm) << endl;
	if (input == InputOrder::FILE)
	{
		cout << "Input file: " << fileName << endl;
	}
	cout << "Input size: " << data.n << endl;

	if (input == InputOrder::rand)
	{
		cout << "Input order: Randomize" << endl;
	}
	else if (input == InputOrder::nsorted)
	{
		cout << "Input order: Nearly sorted" << endl;
	}
	else if (input == InputOrder::sorted)
	{
		cout << "Input order: Sorted" << endl;
	}
	else if (input == InputOrder::rev)
	{
		cout << "Input order: Reversed" << endl;
	}
	cout << "---------------------" << endl;
	// Output parameter
	if (output == OutputParameters::time)
	{
		cout << "Running time: " << data.time << " s" << endl;
	}
	else if (output == OutputParameters::comp)
	{
		cout << "Comparisons: " << data.comparison << endl;
	}
	else if (output == OutputParameters::both)
	{
		cout << "Running time: " << data.time << " s" << endl;
		cout << "Comparisons: " << data.comparison << endl;
	}
	
}


void printAlgorithmMode3(sortingAlgorithm data1, sortingAlgorithm data2, sortingAlgorithm data3, sortingAlgorithm data4, SortingAlgorithms algorithm, OutputParameters output)
{
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << toString(algorithm) << endl;
	cout << "Input size: " << data1.n << endl;
	cout << endl;
	cout << "Input order: Randomize" << endl;
	cout << "---------------------" << endl;
	if (output == OutputParameters::time)
	{
		cout << "Running time: " << data1.time << " s" << endl;
	}
	else if (output == OutputParameters::comp)
	{
		cout << "Comparisons: " << data1.comparison << endl;
	}
	else if (output == OutputParameters::both)
	{
		cout << "Running time: " << data1.time << " s" << endl;
		cout << "Comparisons: " << data1.comparison << endl;
	}
	cout << endl;
	cout << "Input order: Nearly sorted" << endl;
	cout << "---------------------" << endl;
	if (output == OutputParameters::time)
	{
		cout << "Running time: " << data2.time << " s" << endl;
	}
	else if (output == OutputParameters::comp)
	{
		cout << "Comparisons: " << data2.comparison << endl;
	}
	else if (output == OutputParameters::both)
	{
		cout << "Running time: " << data2.time << " s" << endl;
		cout << "Comparisons: " << data2.comparison << endl;
	}
	cout << endl;
	cout << "Input order: Sorted" << endl;
	cout << "---------------------" << endl;
	if (output == OutputParameters::time)
	{
		cout << "Running time: " << data3.time << " s" << endl;
	}
	else if (output == OutputParameters::comp)
	{
		cout << "Comparisons: " << data3.comparison << endl;
	}
	else if (output == OutputParameters::both)
	{
		cout << "Running time: " << data3.time << " s" << endl;
		cout << "Comparisons: " << data3.comparison << endl;
	}
	cout << endl;
	cout << "Input order: Reversed" << endl;
	cout << "---------------------" << endl;
	if (output == OutputParameters::time)
	{
		cout << "Running time: " << data4.time << " s" << endl;
	}
	else if (output == OutputParameters::comp)
	{
		cout << "Comparisons: " << data4.comparison << endl;
	}
	else if (output == OutputParameters::both)
	{
		cout << "Running time: " << data4.time << " s" << endl;
		cout << "Comparisons: " << data4.comparison << endl;
	}
	cout << endl;
	cout << endl;

}


void printComparisonMode(sortingAlgorithm data1, sortingAlgorithm data2,SortingAlgorithms algo1, SortingAlgorithms algo2, InputOrder input, string fileName)
{
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << toString(algo1) << " | " << toString(algo2) << endl;
	if (input == InputOrder::FILE)
	{
		cout << "Input file: " << fileName << endl;
	}
	cout << "Input size: " << data1.n << endl;
	if (input == InputOrder::rand)
	{
		cout << "Input order: Randomize" << endl;
	}
	else if (input == InputOrder::nsorted)
	{
		cout << "Input order: Nearly sorted" << endl;
	}
	else if (input == InputOrder::sorted)
	{
		cout << "Input order: Sorted" << endl;
	}
	else if (input == InputOrder::rev)
	{
		cout << "Input order: Reversed" << endl;
	}
	cout << "---------------------" << endl;
	cout << "Running time: " << data1.time << " s" << " | " << data2.time << " s" << endl;
	cout << "Comparisons: " << data1.comparison << " | " << data2.comparison << endl;
	cout << endl;
}

void outputSortedArray(int* arr, int n)
{
	ofstream fout;
	fout.open("output.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr[i] << " ";
	}
	fout.close();

}
void outputGeneratedData(int* arr, int n)
{
	ofstream fout;
	fout.open("input.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr[i] << " ";
	}
	fout.close();
}






void outputAllGeneratedData(int* arr1, int* arr2, int* arr3, int* arr4, int n)
{
	ofstream fout;
	fout.open("input_1.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr1[i] << " ";
	}
	fout.close();
	fout.open("input_2.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr2[i] << " ";
	}
	fout.close();
	fout.open("input_3.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr3[i] << " ";
	}
	fout.close();
	fout.open("input_4.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << arr4[i] << " ";
	}
	fout.close();

}