#include <iostream>

bool check(std::string str)
{
	int state = 1;
	bool fail = false;
	for(int i=0;i<str.length();i++)
	{
		char x = str[i];
		switch(x)
		{
			case 'h' : 
				if(state==1)
					state =2;
				else if(state==2)
					state=2;
				else if(state==5)
					state = 2;
				else
					fail = true;
				break;
			case 'i' :
				if(state==2)
					state =3;
				else if(state==3)
					state = 3;
				else
					fail = true;
				break;
			case 'r':
				if(state==3)
					state =4;
				else if(state==4)
					state = 4;
				else
					fail = true;
				break;
			case 'e':
				if(state==4)
					state =5;
				else if(state==5)
					state = 5;
				else
					fail = true;
				break;
			default:
				fail = true;
				break;
		}
		if(fail)
			break;
	}
	if(state==5)
		return true;
	else
		return false;
}

int main()
{
	std::string x = "hirreee";
	std::cout << check(x);
}