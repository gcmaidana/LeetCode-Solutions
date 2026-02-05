# link: https://leetcode.com/problems/unique-paths/

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # weird edge case
        if m == n == 1:
            return 1

        dp = [[1]*n for _ in range(m)]
        print(dp)

        for r in range(1, m):le
            for c in range(1, n):
    
                dp[r][c] = dp[r][c - 1] + dp[r - 1][c]
        
        return dp[-1][-1]

       

    
