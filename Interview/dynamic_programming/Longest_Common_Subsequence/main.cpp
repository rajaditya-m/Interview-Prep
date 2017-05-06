#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

void printMat(int** a, int r, int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int LCS(std::vector<char> &v1,std::vector<char> &v2)
{
	int m = v1.size();
	int n = v2.size();

	int** table = new int*[m+1];
	for(int i=0;i<=m;i++)
		table[i] = new int[n+1];

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			table[i][j]=0;
		}
	}
	

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(v1[i-1]==v2[j-1])
			{
				table[i][j] = table[i-1][j-1]+1;
			}
			else
			{
				table[i][j] = std::max(table[i][j-1],table[i-1][j]);
			}
		}
	}

	printMat(table,m+1,n+1);
	std::vector<char> result;

	int res = table[m][n];
	//Now we will retrieve the result
	int i=m;
	int j=n;
	while(i && j)
	{
		if(table[i][j]==table[i-1][j])
		{
			i--;
		}
		else if(table[i][j]==table[i][j-1])
		{
			j--;
		}
		else
		{
			result.push_back(v1[i-1]);
			i--;
			j--;
		}
	}

	std::reverse(result.begin(),result.end());
	std::string resStr(result.begin(),result.end());
	std::cout << "String is " << resStr;

	for(int i=0;i<=m;i++)
		delete[] table[i];
	delete[] table;

	return res;
}

int main()
{
	char A[6]={'a','b','a','z','d','c'};
    char B[6]={'b','a','c','b','a','d'};

    std::vector<char> v1(A,A+sizeof(A)/sizeof(char));
    std::vector<char> v2(B,B+sizeof(B)/sizeof(char));
    std::cout << "Size of LCS is " << LCS(v1,v2);
	return (EXIT_SUCCESS);
}