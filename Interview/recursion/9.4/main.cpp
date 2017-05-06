#include <iostream>
#include <cstdlib>
#include <cmath>

void print_special_rec(int arr[],int len, long long int key, int pres, bool print_braces)
{
	if(print_braces)
		std::cout << "{ ";
	if(key==0)
	{
		if(print_braces)
			std::cout << "}\n";
		return;
	}
	print_special_rec(arr,len,key/2,pres-1,false);
	if(key%2==1)
		std::cout << arr[pres] << " " ;
	if(print_braces)
		std::cout << "}\n";
}

void generate_subset(int arr[],int len)
{
	long long int range = pow(2,len);
	long long int idx = 0;
	for(idx = 0;idx < range;idx++)
	{
		print_special_rec(arr,len,idx,len-1,true);
	}
}

int main()
{
	int x[] = {1,2,3,4,5};
	int len = 5;
	generate_subset(x,5);
}