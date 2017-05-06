#include <iostream>
#include <cstdlib>
#include <algorithm>

void prettyPrintUpperTri2D(int** arr, int r, int c)
{
	for(int i=1;i<r;i++)
	{
		int end = std::min(i,c-1);
		for(int j=1;j<=end;j++)
			std::cout << arr[i][j] << " ";
		std::cout << "\n";
	}
}

int main()
{
	int n,K;

	std::cin >> n;
	std::cin >> K;

	int* arr = new int[n];
	int* dtab = new int[K];

	int** idx_table = new int*[K];
	for(int c=0;c<K;c++)
		idx_table[c] = new int[K];

	int i = 0,a,b;
	int sum;
	// int dim1k = -1;
	// int candI;
	// int candK;
	// int canDist;
	for(i=0;i<n;i++)
	{
		std::cin >> arr[i];
		if(i==0)
		{
			dtab[i] = arr[i];
			//idx_table[i][0] = i;
		}
		else if(i==1)
		{
			dtab[i] = abs(arr[1]-arr[0]);
			idx_table[1][0] = 0;
			idx_table[1][1] = 1;
		}
		else
		{
			int lim = std::min(i,K-1);
			for(a=1;a<=lim;a++)
			{
			
				if(a==1)
				{
					/*
					if(arr[i]<dtab[a])
					{
						dtab[a] = arr[i];
						idx_table[a][0] = i;
					}
					*/
					int fcan = abs(arr[i]-arr[idx_table[1][0]]);
					int scan = abs(arr[i]-arr[idx_table[1][1]]);
					if(fcan<=scan)
					{
						if(fcan<dtab[1])
						{
							dtab[1] = fcan;
							idx_table[1][1] = i;
						}
					}
					else
					{
						if(scan<dtab[1])
						{
							dtab[1] = scan;
							idx_table[1][0] = i;
						}
					}
				}
				else
				{
					sum =0;
					for(b=0;b<a;b++)
					{
						sum += abs(arr[i]-arr[idx_table[a-1][b]]);
					}
					sum += dtab[a-1];
					if(a==i)
					{
						dtab[a] = sum;
						for(int t=0;t<a;t++)
						{
							idx_table[a][t] = idx_table[a-1][t];
						}
						idx_table[a][a] = i;
					}
					else
					{
						if(sum<dtab[a])
						{
							dtab[a] = sum;
							for(int t=0;t<a;t++)
							{
								idx_table[a][t] = idx_table[a-1][t];
							}
							idx_table[a][a] = i;
						}
					}
				}
			}
		}
		// std::cout << "[";
		for(int l=0;l<K;l++)
		{
			std::cout << dtab[l] << "-";
			for(int m=0;m<=l;m++)
			{
				std::cout << idx_table[l][m] << " " ;
			}
			std::cout << "\n";
		}
		std::cout << "]\n";
	}

	std::cout << dtab[K-1];

}