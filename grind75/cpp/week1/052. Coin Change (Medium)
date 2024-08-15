// Problem link: https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int a = 1; a <= amount; ++a)
        {
            for(int c : coins)
            {
                if(a - c >= 0 && dp[a - c] != INT_MAX)
                {
                    dp[a] = std::min(dp[a], 1 + dp[a - c]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
