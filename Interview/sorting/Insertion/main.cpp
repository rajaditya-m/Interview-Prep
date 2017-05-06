#include <iostream>
#include <cstdlib>

void printArr(int* arr, int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void insertionSort(int *arr, int count)
{
	int i,j;
	for (i = 1; i < count; ++i)
	{
		int key = arr[i];
		for (j = i-1; j >=0 && (arr[j]>key); --j)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = key;
		printArr(arr,count);
	}
}

int main()
{
	int x[] = {2,17,90,34,23,14,65,22,0,111};
	printArr(x,10);
	insertionSort(x,10);
	return (EXIT_SUCCESS);
}