#include <iostream>
#include <cstdlib>

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)
int magic_index_distinct(int arr[],int start, int end)
{
	if(end<start || start<0)
		return -1;
	int mid = (start+end)/2;
	int lag = arr[mid]-mid;
	if(lag==0)
	{
		return mid;
	}
	else if(lag<0)
	{
		return magic_index_distinct(arr,mid+1,end);
	}
	else
	{
		return magic_index_distinct(arr,start,mid-1);
	}
}

int magic_index_nondistinct(int arr[],int start, int end)
{
	if(end<start || start<0)
		return -1;
	int mid = (start+end)/2;
	int lag = arr[mid]-mid;

	if(lag==0)
		return mid;

	int leftend = MIN(arr[mid],mid-1);
	int left_val = magic_index_nondistinct(arr,start,leftend);
	if(left_val >= 0)
		return left_val;

	int rightstart = MAX(arr[mid],mid+1);
	int right_val = magic_index_nondistinct(arr,rightstart,end);
	if(right_val >= 0)
		return right_val;

}

int main()
{
	int a1[] = {-40,-20,-1,1,2,3,5,7,9,12,13};
	int a2[] = {-10,-5,2,2,2,3,4,7,9,12,13};
	std::cout <<  "Magic Index in array 1 is " << magic_index_distinct(a1,0,10) << "\n";
	std::cout << "Magic Index in array 2 is " <<  magic_index_nondistinct(a2,0,10) << "\n";
}
