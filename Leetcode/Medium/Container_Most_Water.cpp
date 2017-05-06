class Solution {
public:
    int maxArea(std::vector<int> &height) {
        int n = height.size();
        int maxA = INT_MIN;
		int start = 0;
		int end = n-1;
		while(start<end)
		{
			int curArea = (end-start)*std::min(height[start],height[end]);
			if( curArea > maxA)
				maxA = curArea;
			if(height[start]<height[end])
				start++;
			else 
				end--;
		}
        return maxA;
    }
};