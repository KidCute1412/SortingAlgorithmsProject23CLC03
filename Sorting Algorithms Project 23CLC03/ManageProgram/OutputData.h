#pragma once

#include<iostream>
#include<fstream>
#include<string>

using namespace std;
enum class SortingAlgorithms;
enum class InputOrder;
enum class OutputParameters;
struct sortingAlgorithm;
void printAlgorithmMode12(sortingAlgorithm data, SortingAlgorithms algorithm, InputOrder input, OutputParameters output, string fileName);
void printAlgorithmMode3(sortingAlgorithm data1, sortingAlgorithm data2, sortingAlgorithm data3, sortingAlgorithm data4, SortingAlgorithms algorithm, OutputParameters output);
void printComparisonMode(sortingAlgorithm data1, sortingAlgorithm data2, SortingAlgorithms algo1, SortingAlgorithms algo2, InputOrder input, string fileName);
void outputSortedArray(int* arr, int n);
void outputGeneratedData(int* arr, int n);
void outputAllGeneratedData(int* arr1, int* arr2, int* arr3, int* arr4, int n);