class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        std::sort(num.begin(),num.end());
        int first = 0;
        int last = num.size()-1;
        int bestSum = 99999999;
        while(first<last)
        {
            int second = first+1;
            int third = last;
            while(second<third)
            {
                int sumsoFar = num[first]+num[second]+num[third];
                int diff = (target-sumsoFar);
                int tobeat = abs(target-bestSum);
                if(abs(diff)<tobeat)
                {
                    bestSum = sumsoFar;
                }
                if(diff>0)
                {
                    second++;
                }
                else
                {
                    third--;
                }
            }
            first++;
        }
        return bestSum;
    }
};