#include <iostream>
#include <cstdlib>

void set_array_elems(int* arr,int def_val,int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i]=def_val;
	}
}

int bin_search(int* arr, int n, int target)
{
	int start,end,mid;
	start = 1;
	end = n ;
	while(start<=end)
	{
		mid = (start + end)/2;
		if(mid+1>end)
		{
			return end;
		}
		else if(arr[mid]<target && arr[mid+1] >= target)
		{
			return mid;
		}
		else if(arr[mid] >= target)
		{
			end = mid-1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return 0;
}

int mod_bin_search(int* arr,int* lis,int l,int n,int i)
{
	int start,end,mid;
	start = 1;
	end = l ;
	while(start<=end)
	{
		mid = (start + end)/2;
		if(mid+1>end)
		{
			return end;
		}
		else if(arr[lis[mid]]<arr[i] && arr[lis[mid+1]] >= arr[i])
		{
			return mid;
		}
		else if(arr[lis[mid]] >= arr[i])
		{
			end = mid-1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return 0;
}


void longest_inc_subseq(int* arr,int n, int* slen)
{
	*slen = 0;
	int i,j,k;
	int start,end,mid;
	int* lis = new int[n+1];
	int* parent = new int[n+1];
	set_array_elems(lis,-1,n+1);
	set_array_elems(parent,-1,n+1);
	for(i=0;i<n;i++)
	{
		j = mod_bin_search(arr,lis,*slen,n,i);
		parent[i] =  lis[j];
		if((j== *slen) || (arr[i] < arr[lis[j+1]]))
		{
			lis[j+1] = i;
			if(*slen < j+1)
				*slen = j+1;
		}
	}
}


int main()
{
	int x[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = 16;
	int slen;
	longest_inc_subseq(x,n,&slen);
	std::cout << "Largest increasing subsequence has length  " << slen << "\n";
	return (EXIT_SUCCESS);
}