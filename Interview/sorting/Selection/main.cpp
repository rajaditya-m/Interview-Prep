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

void selectionSort(int *arr, int count)
{
	for (int i = 0; i < count-1; ++i)
	{
		int minPos = i;
		for (int j = i+1; j < count; ++j)
		{
			if(arr[j]<arr[minPos])
			{
				minPos = j;
			}
		}
		int temp = arr[minPos];
		arr[minPos] = arr[i];
		arr[i] = temp;
		printArr(arr,count);
	}
}

int main()
{
	int x[] = {2,17,90,34,23,14,65,22,0,111};
	printArr(x,10);
	selectionSort(x,10);
	return (EXIT_SUCCESS);
}