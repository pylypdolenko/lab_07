// lab_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int* getArray(int size) {
	

	int *a = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> a[i];
		cout << endl;
	}

	return a;
}

void moveElementBack(int *arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}


void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

void shakeSort(int *arr, int size)
{
	int swaps = 0, compars = 0, cycles = 0;

	int start = 1;//comparing element with prev => ignoring index № 0 
	int end = size - 1;

	cout << "shakeSort: START\n\n";

	while (start < end)
	{
		cycles++;

		int lastSwapIndex = end;

		for (int i = end; i >= start; i--) {
			compars++;
			if (arr[i - 1] > arr[i]) {
				lastSwapIndex = i;
				moveElementBack(arr, i);
				swaps++;
			}
		}	
		start = lastSwapIndex + 1;


		cout << "Cycle No " << cycles << " FIRST" << endl;
		cout << "Array: \n";
		printArray(arr, size);
		cout << endl;

		for (int i = start; i <= end; i++) {
			compars++;
			if (arr[i - 1] > arr[i]) {
				lastSwapIndex = i;
				moveElementBack(arr, i);
				swaps++;
			}
		}
		end = lastSwapIndex - 1;

		if (start <= end) {
			cout << "Cycle No " << cycles << " SECOND" << endl;
			cout << "Array: \n";
			printArray(arr, size);
			cout << endl;
		}
	}

	cout << "shakeSort END\n\n";

	cout << "Compars - " << compars << "\n";
	cout << "Swaps - " << swaps << "\n";
}

int main()
{
	int size;

	cout << "Array size = ";
	cin >> size;

	int *array = getArray(size);

	shakeSort(array, size);

	printArray(array, size);

	return 0;
}