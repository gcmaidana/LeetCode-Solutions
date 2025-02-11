// Problem link: https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int currAmount = 1; currAmount <= amount; currAmount++) 
        {
            for (int coin : coins) {
                // check for reachable value to prevent overflow
                if (currAmount - coin >= 0 && dp[currAmount - coin] != INT_MAX) 
                {
                    dp[currAmount] = std::min(dp[currAmount], 1 + dp[currAmount - coin]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
