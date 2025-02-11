// Problem link: https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) { return {0}; }

        std::vector<int> dp(n + 1, 0); // size n + 1, initialize to 0
        dp[1] = 1;
        int nextPowerOfTwo = 2;
        int previousPowerOfTwo = 1;

        for(int i = 2; i <= n; i++)
        {
            if (i == nextPowerOfTwo)
            {
                previousPowerOfTwo = nextPowerOfTwo;
                nextPowerOfTwo = nextPowerOfTwo << 1;
            }
            dp[i] = 1 + dp[i - previousPowerOfTwo];
        }
        return dp;         
      
    }
};
