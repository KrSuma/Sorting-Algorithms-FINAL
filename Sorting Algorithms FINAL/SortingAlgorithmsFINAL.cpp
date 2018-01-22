#include "stdafx.h"

using namespace std;

/*main function*/

int main()
{
	cout << "Enter the number of the element you wish to input." << endl;
	int length;
	cin >> length;

	int *array = new int[length];

	cout << "Enter the numbers you want to input." << endl;

	for (int i = 0; i < length; i++)
	{
		cin >> array[i];
	}

	cout << "Enter your options: " << endl;
	cout << "1. heapsort" << endl;
	cout << "2. quicksort" << endl;
	cout << "3. bubblesort" << endl;
	cout << "4. insertionsort" << endl;
	cout << "5. selectionsort" << endl;
	cout << "6. shellsort" << endl;
	cout << "7. countingsort (NOT FINISHED YET)" << endl;
	cout << "Enter: ";

	int answer;
	cin >> answer;

	switch (answer)
	{
	case 1:
		heapsort(array, length);
		cout << "printing out the sorted sequence: " << endl;
		print(array, length);
		break;

	case 2:
		quicksort(array, 0, length - 1);
		cout << "printing out the sorted sequence: " << endl;
		print(array, length);
		break;

	case 3:
		bubblesort(array, length);
		cout << "printing out the sorted sequence: " << endl;
		print(array, length);
		break;

	case 4:
		insertionsort(array, length);
		cout << "printing out the sorted sequence: " << endl;
		print(array, length);
		break;

	case 5:
		selectionsort(array, length);
		cout << "printing out the sorted sequence: " << endl;
		print(array, length);
		break;

	case 6:
		shellsort(array, length);
		cout << "printing out the sorted sequence: " << endl;
		print(array, length);
		break;
		/*
		case 7:
		countingsort(array, length);
		cout << "printing out the sorted sequence: " << endl;
		print(array, length);
		break;
		*/
	}
	delete[] array;
	return 0;
}