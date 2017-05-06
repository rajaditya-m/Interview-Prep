#include <iostream>
#include <cstdlib>

//Count the number of paths 
int robotPath(int x,int y,int n)
{
	if(x==n && y==n)
	{
		return 1;
	}
	return robotPath(x+1,y,n) + robotPath(x,y+1,n);
}

//Enumerate all the possible paths 
