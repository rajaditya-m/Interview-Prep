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


void getPivot(int* arr, int start, int end)
{
	int pivotIdx = (start+end)/2;
	int tmp = arr[start];
	arr[start] = arr[pivotIdx];
	arr[pivotIdx] = tmp;
}

void getPivotRandomized(int* arr,int start, int end)
{
	int range = (end-start)+1;
	int pivotIdx = (rand()%range)+start;
	int tmp = arr[start];
	arr[start] = arr[pivotIdx];
	arr[pivotIdx] = tmp;
}


int partitionArr(int* arr, int start, int end)
{
	getPivotRandomized(arr,start,end);
	int pivot = arr[start];
	int i=start-1;
	int j=end+1;
	while(1)
	{
		do
		{
			j--;
		}while(arr[j]>pivot);
		do
		{
			i++;
		}while(arr[i]<pivot);
		if(i<j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		else
		{
			return j;
		}
	}
}

void quickSort(int* arr, int start, int end)
{
	int len = (end-start)+1;
	if(len<2)
		return;
	int pIdx = partitionArr(arr,start,end);
	quickSort(arr,start,pIdx);
	quickSort(arr,pIdx+1,end);
}

int main()
{
	int x[] = {90,17,134,223,14,22,65,100,2,111};
	quickSort(x,0,9);
	//int r = partitionArr(x,0,9);
	//std::cout << "Pivot is " << r << "\n";
	printArr(x,10);
	return (EXIT_SUCCESS);
}