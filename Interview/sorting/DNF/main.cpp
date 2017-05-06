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

void dutchNationalFlag(int *arr,int count)
{
	int low = 0;
	int mid = 0;
	int high = count-1;
	while(mid<high)
	{
		if(arr[mid]==0)
		{
			int tmp = arr[low];
			arr[low] = arr[mid];
			arr[mid] = tmp;
			mid++;
			low++;
		}
		else if(arr[mid]==1)
		{
			mid++;
		}
		else
		{
			int tmp = arr[high];
			arr[high] = arr[mid];
			arr[mid] = tmp;
			high--;
		}
	}
}


int main()
{
	int x[] = {2,0,0,1,2,1,1,2,0,1};
	printArr(x,10);
	dutchNationalFlag(x,10);
	printArr(x,10);
	return (EXIT_SUCCESS);
}