class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)
            return 0;
        int minPriceSoFar = prices[0];
        int maxProfitSoFar = INT_MIN;
        for(int i=1;i<prices.size();i++)
        {
            int profit =prices[i]-minPriceSoFar;
            maxProfitSoFar = std::max(profit,maxProfitSoFar);
            minPriceSoFar = std::min(minPriceSoFar,prices[i]);
        }
        return std::max(0,maxProfitSoFar);
    }
};