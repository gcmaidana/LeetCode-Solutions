// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i = 1; i < n; i++)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
            }
            else
            {
                int currentProfit = prices[i] - buy;
                maxProfit = std::max(maxProfit, currentProfit);
            }
        }
        return maxProfit;
        
    }
};
