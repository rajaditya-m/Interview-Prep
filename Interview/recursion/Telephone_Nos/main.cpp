#include <iostream>
#include <cstdlib>

char getCharKey(char key, int place)
{
	char retVal;
	switch(key)
	{
		case '2' : 
			switch(place)
			{
				case 0: retVal = 'A'; break;
				case 1: retVal = 'B'; break;
				case 2: retVal = 'C'; break;
			}
			break;
		case '3' : 
			switch(place)
			{
				case 0: retVal = 'D'; break;
				case 1: retVal = 'E'; break;
				case 2: retVal = 'F'; break;
			}
			break;
		case '4' : 
			switch(place)
			{
				case 0: retVal = 'G'; break;
				case 1: retVal = 'H'; break;
				case 2: retVal = 'I'; break;
			}
			break;
		case '5' : 
			switch(place)
			{
				case 0: retVal = 'J'; break;
				case 1: retVal = 'K'; break;
				case 2: retVal = 'L'; break;
			}
			break;
		case '6' : 
			switch(place)
			{
				case 0: retVal = 'M'; break;
				case 1: retVal = 'N'; break;
				case 2: retVal = 'O'; break;
			}
			break;
		case '7' : 
			switch(place)
			{
				case 0: retVal = 'P'; break;
				case 1: retVal = 'R'; break;
				case 2: retVal = 'S'; break;
			}
			break;
		case '8' : 
			switch(place)
			{
				case 0: retVal = 'T'; break;
				case 1: retVal = 'U'; break;
				case 2: retVal = 'V'; break;
			}
			break;
		case '9' : 
			switch(place)
			{
				case 0: retVal = 'W'; break;
				case 1: retVal = 'X'; break;
				case 2: retVal = 'Y'; break;
			}
			break;
	}
	return retVal;
}

void printTelephoneCode(std::string telephone, std::string prefix)
{
	if(telephone[0]=='\0')
	{
		std::cout << prefix << "\n";
		return;
	}
	char curDig = telephone[0];
	char char1 = getCharKey(curDig,0);
	char char2 = getCharKey(curDig,1);
	char char3 = getCharKey(curDig,2);
	std::string from1 = telephone.substr(1);
	printTelephoneCode(from1,prefix+char1);
	printTelephoneCode(from1,prefix+char2);
	printTelephoneCode(from1,prefix+char3);
}

int main()
{
	std::string x = "23";
	printTelephoneCode(x,"");
	return (EXIT_SUCCESS);
}