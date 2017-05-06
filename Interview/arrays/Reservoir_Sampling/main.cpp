#include <iostream>
#include <cstdlib>

void printArr(int *arr,int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	int k;
	std::cout << "Enter the value of k:";
	std::cin >> k;

	int* reservoir = new int[k];
	memset(reservoir,0,k*sizeof(int));

	int counter=0;
	int num;
	while(true)
	{
		std::cout << "Please enter 0 to exit:";
		std::cin >> num;
		if(num==0)
			break;
		if(counter<k)
		{
			reservoir[counter]= num;
		}
		else
		{
			//Generate a number between 0 and counter
			int r = rand()%(counter+1);
			if(r<k)
			{
				reservoir[r] = num;
			}
		}
		printArr(reservoir,k);
		counter++;
	}
	return(EXIT_SUCCESS);	
}