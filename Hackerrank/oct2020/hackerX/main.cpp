#include <iostream>

class ListNode
{
public:
	ListNode()
	{
		idx = -1;
		next = NULL;
	}
	int idx;
	ListNode* next; 
};

class DataRep
{	
public:
	DataRep()
	{
		t = f = -1;
		head = tail = NULL;
	}
	int t;
	int f;
	ListNode* head;
	ListNode* tail;
};

int main()
{
	DataRep data_array[100];
	int N;
	int i,j;
	int timeDiff, freqDiff;
	std::cin >> N;
	for(i=0;i<N;i++)
	{
		std::cin >> data_array[i].t >> data_array[i].f ;
	}
	for(i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			timeDiff = data_array[j].t - data_array[i].t;
			freqDiff = abs(data_array[j].f - data_array[i].f);
			if(freqDiff>timeDiff)
			{
				//Add to graph 
				ListNode* n = new ListNode();
				n->idx = i;
				ListNode* sn = new ListNode();
				sn->idx = j;
				//Add n to j's linked list 
				if(!data_array[j].head)
				{
					data_array[j].head = data_array[j].tail = n;
				}
				else
				{
					data_array[j].tail->next = n;
					data_array[j].tail = n;
				}
				//Add sn to i's linked list 
				if(!data_array[i].head)
				{
					data_array[i].head = data_array[i].tail = sn;
				}
				else
				{
					data_array[i].tail->next = sn;
					data_array[i].tail = sn;
				}
				std::cout << "I:" << i << " J:" << j << "\n";
			}
		}
	}
}