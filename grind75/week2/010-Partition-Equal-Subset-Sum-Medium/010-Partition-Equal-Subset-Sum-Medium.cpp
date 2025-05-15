// Problem link: https://leetcode.com/problems/partition-equal-subset-sum/

// Not the most optimal, but an elegant solution nonetheless using a set
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Base case check
        // Sum of nums must be even, otherwise you can't split into two equal partitions
        // For example, if the sum is 7, it's impossible to divide it into two equal parts
        int total = 0;
        for (int num : nums) 
        {
            total += num;
        }
        if (total % 2 != 0) 
        {
            return false;
        }

        // Each partition must sum to total / 2
        // E.g., for [1,5,11,5] => 1 + 5 + 11 + 5 = 22, so target = 11
        int target = total / 2;

        // To build up to the target, we either take or don't take each number — like knapsack
        // ------
        // Duplicates won't get stored in an unordered_set
        unordered_set<int> dp;
        dp.insert(0);  // Base case: sum of 0 is always possible

        for (int i = 0; i < nums.size(); i++) 
        {
            // Cannot update dp set while iterating over it, so use a separate set: nextDP
            unordered_set<int> nextDP;
            for (int t : dp) 
            {
                nextDP.insert(t + nums[i]);
                nextDP.insert(t);
            }
            dp = nextDP;
        }
        print("Possible subset sums:", dp)
        // Final check: was the target sum reachable?
        return dp.count(target) > 0;
    }
};

// Optimal 1-D DP approach

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Calculate the total sum of the array
        int total = 0;
        for (int num : nums) 
        {
            total += num;
        }

        // If the total sum is odd, we can't split it into two equal subsets
        if (total % 2 != 0) 
        {
            return false;
        }

        // Each partition must sum to total / 2
        int target = total / 2;

        // dp[i] = true means we can form sum i using some subset of nums
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: sum 0 is always possible with no elements

        // Iterate through each number in the input array
        for (int num : nums) 
        {
            // Loop backwards to avoid using the same number more than once in this round
            for (int j = target; j >= num; j--) 
            {
                if (dp[j - num]) 
                {
                    dp[j] = true;
                }
            }
        }

        // Final check: can we form the target sum?
        return dp[target];
    }
};
