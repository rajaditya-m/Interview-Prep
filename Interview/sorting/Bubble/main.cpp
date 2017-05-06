#include <iostream>
#include <cstdlib>
#include <algorithm>

void printArr(int* arr, int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void bubbleSort(int *arr, int count)
{
	bool swapOccured = true;
	while(swapOccured)
	{
		swapOccured = false;
		for(int i=0;i<count-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				swapOccured = true;
				std::swap(arr[i],arr[i+1]);
			}
		}
		printArr(arr,count);
	}
}

int main()
{
	int x[] = {2,17,90,34,23,14,65,22,0,111};
	printArr(x,10);
	bubbleSort(x,10);
	return (EXIT_SUCCESS);
}