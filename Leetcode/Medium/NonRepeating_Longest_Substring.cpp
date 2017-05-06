class Solution {
public:
int lengthOfLongestSubstring(std::string s)
{
	int len = s.length();
	int head = 0;
	int max_len = 0;
	int len_so_far = 0;
	int storage[256];
	for(int i=0;i<256;i++) storage[i] = -1;
	// memset(storage,0,sizeof(int)*256);
	for(int i=0;i<len;i++)
	{
		char x = s[i];
		//It could be beyond the current head in which case simply add it to the list of
		//the 
		if(storage[x]<head)
		{
			storage[x] = i;
			len_so_far++;
		}
		else
		{
			//We have hit a snag 
			//reset head to the next elem 
			head = storage[x]+1;
			storage[x] = i;
			if(len_so_far>max_len)
			{
				max_len = len_so_far;
			}
			len_so_far = (i-head)+1;
			//Done do anything its still len so far
		}
	}
	if(max_len>len_so_far)
		return max_len;
	else
		return len_so_far;
}

};