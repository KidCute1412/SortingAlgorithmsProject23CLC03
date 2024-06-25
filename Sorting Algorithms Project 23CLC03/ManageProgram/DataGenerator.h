#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<cmath>
#include<string>


void generateRandomData(int*& arr, int n);

void generateSortedData(int*& arr, int n);

void generateReverseSortedData(int*& arr, int n);

void generateNearlySortedData(int*& arr, int n);




void readFileData(int*& arr, int& n, std::string& fileName);



void copyArray(int*& arr1, int*& arr2, int n);