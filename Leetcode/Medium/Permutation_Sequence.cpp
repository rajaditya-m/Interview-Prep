class Solution {
public:
    int fac(int x)
{
	int pdk = 1;
	for(int i=0;i<x;i++)
		pdk *= (i+1);
	return pdk;
}

std::string getPermutation(int n, int k)
{
	std::vector<int> v;
	k--;
	std::string res;
	for(int i=0;i<n;i++)
		v.push_back(i+1);
	bool finished = false;
	while(!finished)
	{
		if(k==0)
		{
			for(int j=0;j<v.size();j++)
				res.push_back('0'+ v[j]);
			finished = true;
		}
		else
		{
			int id = (k)/fac(n-1);
			res.push_back('0'+ v[id]);
			v[id] = v[0];
			v.erase(v.begin());
			std::sort(v.begin(),v.end());
			k = (k)%(fac(n-1));
			n--;
		}
	}
	return res;
}
};