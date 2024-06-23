#include "DataGenerator.h"



void generateRandomData(int*& arr, int n)
{
	arr = new int[n];
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < n; i++)
	{
		// Use scaling to ensure values cover the range [-n, n)
		int randomValue = abs(static_cast<int>((rand() / (static_cast<double>(RAND_MAX) + 1)) * (2 * n)));
		arr[i] = randomValue - n;  // -n
	}
}
void generateSortedData(int*& arr, int n)
{
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
}
void generateReverseSortedData(int*& arr, int n)
{
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
}
void generateNearlySortedData(int*& arr, int n)
{
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < n / 10; i++)
	{
		int randomIndex1 = rand() % n;
		int randomIndex2 = rand() % n;
		std::swap(arr[randomIndex1], arr[randomIndex2]);
	}
}


void readFileData(int*& arr, int& n, std::string& fileName)
{
	std::ifstream fin;
	fin.open(fileName);
	if (!fin.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		fin.close();
		return;
	}
	fin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i];
	}
	fin.close();
}


void copyArray(int*& arr1, int*& arr2, int n)
{
	arr2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr2[i] = arr1[i];
	}
}
