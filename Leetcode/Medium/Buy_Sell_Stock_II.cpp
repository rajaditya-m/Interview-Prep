class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        int profit=0;
        for(int k=0;k<len-1;k++)
        {
            if(prices[k]<prices[k+1])
                profit += (prices[k+1]-prices[k]);
        }
        return profit;
    }
};