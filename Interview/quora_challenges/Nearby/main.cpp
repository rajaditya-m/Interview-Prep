#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

class CartesianPoint
{
public:
	CartesianPoint(double x, double y):x_(x),y_(y){}
	
	double getX() const { return x_;}
	
	double getY() const { return y_;}
	
	double getDistance(CartesianPoint p)
	{
		double dS = ((x_-p.getX())*(x_-p.getX())) + ((y_-p.getY())*(y_-p.getY()));
		return(sqrt(dS));
	}

	bool operator<(const CartesianPoint& p) const
	{
		if(x_<p.getX())
			return true;
		else if(p.getX()>x_)
			return false;
		else
		{
			return (y_<p.getY());
		}
	}

	friend std::ostream& operator<<(std::ostream& o,const CartesianPoint& obj) ;
private:	
	double x_;
	double y_;
};

std::ostream& operator<<(std::ostream& o,const CartesianPoint& obj) 
{
	o << "[" << obj.x_ << "," << obj.y_ << "]" ;
	return o;
}

class TopicDS
{
public:
	TopicDS(int id,CartesianPoint loc):id_(id),loc_(loc){}
	
	CartesianPoint getLoc() const {return loc_;}
	
	bool operator<(const TopicDS &obj) const
	{
		return (loc_<obj.getLoc());
	}

	friend std::ostream& operator<<(std::ostream& o, TopicDS &obj);

private:
	int id_;
	CartesianPoint loc_;
};

std::ostream& operator<<(std::ostream& o, TopicDS &obj)
{
	o << "{" << obj.id_ << "}-" << obj.loc_ ;
	return o;
}

class KDTreeNode
{

private:
	KDTreeNode* left;
	KDTreeNode* right;
	TopicDS data;
};


class KDTree
{
	public
};

void printVec(std::vector<TopicDS> &vec)
{
	std::vector<TopicDS>::iterator it;
	for(it=vec.begin();it!=vec.end();++it)
	{
		std::cout << *it << "\n";
	}
}

int main()
{
	int nosTopics;
	std::vector<TopicDS> vT;
	std::cin >> nosTopics;
	int cntr = nosTopics;
	double xC,yC;
	int tid;
	while(cntr)
	{

		std::cin >> tid >> xC >> yC;
		TopicDS tTop(tid,CartesianPoint(xC,yC));
		vT.push_back(tTop);
		cntr--;
	}
	std::sort(vT.begin(),vT.end());
	printVec(vT);
	return(EXIT_SUCCESS);
}
