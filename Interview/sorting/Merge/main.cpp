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

//Assume that the given array has 
//indices from start-mid sorted
// and indices from mid+1 to end sorted 
void merge(int *arr,int start,int end,int mid)
{
	int len = (end-start)+1;
	int* buffer = new int[len];
	int pntr1 = start;
	int pntr2 = mid+1;
	int curCntr=0;
	while((pntr1<=mid) && (pntr2<=end))
	{
		if(arr[pntr1]<arr[pntr2])
		{
			buffer[curCntr++] = arr[pntr1++];
		}
		else
		{
			buffer[curCntr++] = arr[pntr2++];
		}
	}
	if(pntr1>mid)
	{
		for(int j=curCntr;j<len;j++)
		{
			buffer[j] = arr[pntr2++];
		}
	}
	else if(pntr2>end)
	{
		for(int j=curCntr;j<len;j++)
		{
			buffer[j] = arr[pntr1++];
		}
	}
	int k=start;
	for(int i=0;i<len;i++,k++)
	{
		arr[k] = buffer[i];
	}
	delete[] buffer;
}


void mergeSort(int *arr, int start, int end)
{
	int len = (end-start)+1;
	if(len<2)
	{
		return ;
	}
	else
	{
		int mid = (start+end)/2;
		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,start,end,mid);
	}
}


int main()
{
	int x[] = {90,17,134,223,14,22,65,100,2,111};
	mergeSort(x,0,9);
	printArr(x,10);
	return (EXIT_SUCCESS);
}