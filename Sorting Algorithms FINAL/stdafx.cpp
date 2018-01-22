#include "stdafx.h"

#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//sorting binary decision trees

//----------------------------------------------------------------------------------------------------//

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapsort(int arr[], int input)
{
	// Build heap (rearrange array)
	for (int i = input / 2 - 1; i >= 0; i--)
		heapify(arr, input, i);

	// One by one extract an element from heap
	for (int i = input - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

//----------------------------------------------------------------------------------------------------//

/* This function takes last element as pivot, places the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot; high = length - 1.
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

//Tail-recursive quicksort.
void TRquicksort(int arr[], int low, int high)
{
	while (low < high)
	{
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi - 1);
		low = pi + 1;
	}
}


//----------------------------------------------------------------------------------------------------//

//modified version of bubblesort, that includes a flag to check if the swap has been made.
//also does not count the last element (since its already done).
//if there was no swap, terminates the loop early.
void bubblesort(int array[], int input)
{
	int length = input;

	for (int i = 0; i < length - 1; i++)
	{

		int endIndex = length - i;
		bool swapped = false;

		for (int j = 0; j < endIndex - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				swapped = true;
			}
		}

		if (!swapped)
		{
			cout << "early termination on iteration: " << i + 1 << endl;
			break;
		}
	}
}

//----------------------------------------------------------------------------------------------------//

//iterates up the array, growing the sorted list behind it.
//finds the correct position within the sorted list, shifts all the larger values up to make a space,
//and inserts into that correct position.
void insertionsort(int array[], int input)
{
	int key, j;

	for (int i = 1; i < input; i++)
	{
		key = array[i];
		j = i - 1;

		//compares all elements in array[0,...,input-1]
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

//----------------------------------------------------------------------------------------------------//

//we compare two pairs, 1st and 2nd, and then swaps it if 1st element is bigger than the 2nd element.
void selectionsort(int array[], int input)
{
	for (int i = 0; i < input - 1; i++)
	{
		int smallestIndex = i;
		for (int j = i + 1; j = input; j++)
		{
			if (array[smallestIndex] > array[j])
				smallestIndex = j;
		}
		swap(array[i], array[smallestIndex]);
	}
}

//----------------------------------------------------------------------------------------------------//
/*
void countingsort(int array[], int input)
{
int *CountArr = new int[input];

for (int i = 0; i < input; i++)
{
CountArr[array[i]]++;
}

int outputindex = 0;
for (int j = 0; j < bucket; j++)
{
while (CountArr[j]--)
array[outputindex++] = j;
}

}
*/
//----------------------------------------------------------------------------------------------------//

void shellsort(int array[], int input)
{
	// Start with a big gap, then reduce the gap
	for (int gap = input / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (int i = gap; i < input; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = array[i];

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			//  put temp (the original a[i]) in its correct location
			array[j] = temp;
		}
	}
}

void print(int array[], int input)
{
	for (int i = 0; i < input; i++)
		cout << array[i] << " ";
	cout << endl;
}


