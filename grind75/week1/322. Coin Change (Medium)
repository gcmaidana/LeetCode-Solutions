# Question link: https://leetcode.com/problems/coin-change/description/

# The difficulty in this problem is you can't use a greedy approach
# For example with this input
# [1, 3, 4, 5] amount = 7
# You might think 5 + 1 + 1 works great, but it doesn't. We can use 4 + 3 to use less coins to reach amount

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1) # len -> 0 up to amount
        dp[0] = 0

        for a in range(1, amount + 1):
            for c in coins:
                if a - c >= 0:
                    dp[a] = min(dp[a], 1 + dp[a - c])
        return dp[amount] if dp[amount] != float('inf') else -1

        
