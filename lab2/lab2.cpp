#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <math.h>
using namespace std;

int BinarySearch(int* array, int size, int key)//Binary search
{
	int left = 0, right = size - 1, mid = 0;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (array[mid] == key) return mid;
		if (array[mid] > key)  right = mid + 1;
		else if (array[mid] < key)  left = mid - 1;
	}
	if (array[mid] != key)return -1;
	else return mid;
}

void QuickSort(int* array, int left_input, int right_input, int size)//Quick sorting
{
	if (left_input != 0 || right_input != size - 1) return;
	int mid = (left_input + right_input) / 2;
	int left = left_input, right = right_input;
	while (left <= right)
	{
		while (array[left] < array[mid])left++;
		while (array[right] > array[mid])right--;
		if (left <= right)
		{
			swap(array[left], array[right]);
			left++;
			right--;
		}
		if (left_input < right)QuickSort(array, left_input, right, size);
		if (right_input > left)QuickSort(array, left, right_input, size);
	}
}

void InsertionSort(int* array, int size)//Sorting with inserts
{
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--) swap(array[j - 1], array[j]);
}

void BogoSort(int* array, int size)//Dumb sorting
{
	while (true)
	{
		bool flag = true;
		for (int i = 1; i < size && flag; i++) if (array[i - 1] > array[i])flag = false;
		if (flag) return;

		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i < size; i++) swap(array[i], array[rand() % size]);
	}
}

void СountingSort(char* array, int size)//Sorting by counting
{
	int* char_array = new int[256];
	for (int i = 0; i < 256; i++)char_array[i] = 0;
	for (int i = 0; i < size; i++)char_array[array[i]]++;
	int j = 0;
	for (int i = 0; i < 256; i++) {
		while (char_array[i]) {
			array[j] = i;
			j++;
			char_array[i]--;
		}
	}
}

void TimeTest(int size, int max_value)//Sorting time calculation function
{
	int* array1 = new int[size];//Creating test arrays
	int* array2 = new int[size];
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < size; i++)array1[i] = array2[i] = rand() % max_value; // Filling two arrays with random values

	chrono::high_resolution_clock::time_point start1 = chrono::high_resolution_clock::now();
	QuickSort(array1, 0, size - 1, size);
	chrono::high_resolution_clock::time_point end1 = chrono::high_resolution_clock::now();
	chrono::duration<float> t1 = end1 - start1;// Calculation of the time it takes to sort

	chrono::high_resolution_clock::time_point start2 = chrono::high_resolution_clock::now();
	InsertionSort(array2, size);
	chrono::high_resolution_clock::time_point end2 = chrono::high_resolution_clock::now();
	chrono::duration<float> t2 = end2 - start2;

	cout << "QuickSort with " << size << " numbers spend " << t1.count() << " seconds\n";
	cout << "InsertionSort with " << size << " numbers spend " << t2.count() << " seconds\n";

	delete[] array1;
	delete[] array2;
}

int main()
{
	cout << "Create an array of 5 elements in order and find the index of element two\n";
	int size = 5;
	int* array = new int[size];
	int* arrayQsort = new int[size];
	int* arrayIsort = new int[size];
	int* arrayBsort = new int[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = i;
		cout << i << " - element: " << array[i] << endl;
	}
	cout << "Item index with value two: " << BinarySearch(array, size, 2) << endl;
	cout << "Create an array of four elements filled in descending order\n";
	for (int i = 1; i < size; i++)
	{
		arrayQsort[i] = size - i;
		arrayIsort[i] = size - i;
		arrayBsort[i] = size - i;
		cout << i << " - element: " << arrayQsort[i] << endl;
	}
	cout << "Now let's sort it with the quick sort option\n";
	QuickSort(arrayQsort, 0, size - 1, size);
	for (int i = 1; i < size; i++) cout << i << " - element: " << arrayQsort[i] << endl;
	delete[] arrayQsort;
	cout << "Now let's sort it by sorting with inserts\n";
	InsertionSort(arrayIsort, size);
	for (int i = 1; i < size; i++) cout << i << " - element: " << arrayIsort[i] << endl;
	delete[] arrayIsort;
	cout << "Now let's sort it with a silly sorting\n";
	BogoSort(arrayBsort, size);
	for (int i = 1; i < size; i++) cout << i << " - element: " << arrayBsort[i] << endl;
	delete[] arrayBsort;
	cout << "Create an array filled with the Latin alphabet in random order: \n";
	char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char* RandomAlphabet = new char[26];
	int index;
	for (int i = 0; i < 26; i++)
	{
		index = rand() % 26;
		RandomAlphabet[i] = alphabet[index];
		cout << RandomAlphabet[i] << " ";
	}
	cout << endl << "Now sort this array by counting\n";
	СountingSort(RandomAlphabet, 26);
	for (int i = 0; i < 26; i++)cout << RandomAlphabet[i] << " ";
	cout << endl << "Now let's compare the two types of sorting in terms of running time, measured for arrays of size 100 and a maximum value of 2500\n";
	TimeTest(100, 2500);
}

