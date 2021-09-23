class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrices = INT_MAX;
        int maxProfits = 0;
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < minPrices)
                minPrices = prices[i];
            else if (maxProfits < prices[i] - minPrices){
                maxProfits = prices[i] - minPrices;
            }
        }
        return maxProfits;
    }
};