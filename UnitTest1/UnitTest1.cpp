#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab2\lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(binary_search)
		{
			int* array = new int[3];
			array[0] = 1;
			array[1] = 2;
			array[2] = 3;
			Assert::IsTrue(BinarySearch(array, 3, 2) == 1);
		}
		TEST_METHOD(quick_sort)
		{
			int* array = new int[3];
			array[0] = 2;
			array[1] = 1;
			array[2] = 3;
			QuickSort(array, 12, 123, 3);
			Assert::IsTrue(array[0] == 2 && array[1] == 1 && array[2] == 3);
			QuickSort(array, 0, 2, 3);
			Assert::IsTrue(array[0] == 1 && array[1] == 2 && array[2] == 3);
		}
		TEST_METHOD(insertion_sort)
		{
			int* array = new int[3];
			array[0] = 2;
			array[1] = 1;
			array[2] = 3;
			InsertionSort(array, 3);
			Assert::IsTrue(array[0] == 1 && array[1] == 2 && array[2] == 3);
		}
		TEST_METHOD(bogo_sort)
		{
			int* array = new int[3];
			array[0] = 2;
			array[1] = 1;
			array[2] = 3;
			BogoSort(array, 3);
			Assert::IsTrue(array[0] == 1 && array[1] == 2 && array[2] == 3);
		}
		TEST_METHOD(counting_sort)
		{
			char* array = new char[3];
			array[0] = 'c';
			array[1] = 'a';
			array[2] = 'b';
			ÑountingSort(array, 3);
			Assert::IsTrue(array[0] == 'a' && array[1] == 'b' && array[2] == 'c');
		}

	};
}
