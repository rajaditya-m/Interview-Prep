#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <set>

class Domino
{
public:
	Domino()
	{
		num1 = -1;
		num2=  -1;
	}
	void setPair(int n1,int n2)
	{
		if(n1>n2)
		{
			num1 = n2;
			num2 = n1;
		}
		else
		{
			num1 = n1;
			num2 = n2;
		}
	}
	
	bool operator<(const Domino &obj) const
	{
		if(num1<obj.num1)
			return true;
		else if(num1==obj.num1)
			return num2<obj.num2;
		else
			return false;
	}
	
	friend std::ostream& operator<<(std::ostream& o,const Domino &d);

	int num1;
	int num2;
	
};

std::ostream& operator<<(std::ostream& o,const Domino &d)
{
	o << "[" << d.num1 << "," << d.num2 << "]" ;
	return o;
}

class DominoBox
{
public:
	
	DominoBox(int arr[])
	{
		for(int i=0;i<10;i=i+2)
		{
			boxset[i/2].setPair(arr[i],arr[i+1]);
		}
	}

	friend std::ostream& operator<<(std::ostream& o,const DominoBox &b) ;

	bool operator<(const DominoBox &box)const 
	{
		for(int i=0;i<5;i++)
		{
			if(boxset[i].num1<box.boxset[i].num1 || boxset[i].num2<box.boxset[i].num2)
			{
				return true;
			}
		}
		return false;
	}

	void sortInOrder()
	{
		std::sort(boxset,boxset+5);
	}

	Domino boxset[5];
};

std::ostream& operator<<(std::ostream& o,const DominoBox &b) 
{
	int i;
	for(i=0;i<5;i++)
		o << b.boxset[i];
	return o;
}

class DominoChecker
{
public:
	bool addBox(int arr[])
	{
		DominoBox* newBox = new DominoBox(arr);
		std::cout <<"Trying to insert:";
		newBox->sortInOrder();
		std::cout << *newBox << "\n";
		std::pair<std::set<DominoBox>::iterator,bool> ret;
		ret = set_ds.insert(*newBox);
		return ret.second;
	}

	void print()
	{
		std::set<DominoBox>::iterator it;
		for(it=set_ds.begin();it!=set_ds.end();it++);
			std::cout << *it;
	}
private:
	std::set<DominoBox> set_ds;
};

int main()
{
	int x1[] = {7,4,0,2,9,1,3,3,5,6};
	int x2[] = {7,4,0,2,3,3,6,5,9,9};
	int x3[] = {2,0,9,1,3,3,6,5,4,7};

	DominoChecker* myObj = new DominoChecker();
	std::cout << "Inserting 1st element.\n";
	bool res1 = myObj->addBox(x1);
	std::cout << "Insertion successful:" << res1 << "\n";
	std::cout << "Inserting 2nd element.\n";
	bool res2 = myObj->addBox(x2);
	std::cout << "Insertion successful:" << res2 << "\n";
	std::cout << "Inserting 3rd element.\n";
	bool res3 = myObj->addBox(x3);
	std::cout << "Insertion successful:" << res3 << "\n";

	return(EXIT_SUCCESS);
}
