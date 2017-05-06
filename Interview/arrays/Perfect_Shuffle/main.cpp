#include <iostream>
#include <cstdlib>

void perfectShuffle(int* arr,int n)
{
	int idx;
	for(idx=n-1;idx>=0;idx--)
	{
		//Generate a random number betwen 0<= r <= idx
		int r = rand()%(idx+1);
		//Swap between this and idx
		int temp = arr[r];
		arr[r] = arr[idx];
		arr[idx] = temp; 
	}
}
void printArr(int* arr, int n)
{
	for(int i=0;i<n;i++)
	{
		std::cout << arr[i] << " " ;
	}
	std::cout << "\n";
}

int main()
{
	int arr[]= {1,2,3,4,5,6,7,8,9,10};
	int cnt=0;
	while(cnt++<10)
	{
		perfectShuffle(arr,10);
		printArr(arr,10);
	}
	return (EXIT_SUCCESS);
}