# Good solution, not the most optimal
# Most optimal is 1-D DP array
class Solution:
    def canPartition(self, nums: List[int]) -> bool:

        # base case check
        # sum of nums divided by 2 must be an even number, otherwise you can't have two equal partitions
        # such as if the sum of the input is like 7 or something, then we cant obviously have two equal
        # partitions
        total = sum(nums)
        if total % 2 != 0:
            return False

        # Each partition must be equal to the total sum of the nums array divided by 2
        # E.g., for [1,5,11,5] => 1 + 5 + 11 + 5 = 22, so 22 / 2 = 11
        # So each partition must sum up to 11
        target = total // 2
        
        # to build up to target, we either take or don't take, like knapsack
        # ------
        # duplicates wont get stored in the set
        dp = set()
        dp.add(0) # base case

        for i in range(len(nums)):
            # Cannot update dp set while iterating over it, so use a separate set, nextDP
            nextDP = set()
            for t in dp:
                nextDP.add(t + nums[i])
                nextDP.add(t) 
            dp = nextDP

        return True if target in dp else False


# Optimal 1-D DP Approach!

class Solution:
    def canPartition(self, nums: List[int]) -> bool:

        total = sum(nums)

        if total % 2 != 0:
            return False
        
        target = total // 2

        # dp[i] = True if we can form sum i using some subset of nums
        dp = [False] * (target + 1)
        dp[0] = True # base case: sum of 0 is always possible with no elements
        
        for num in nums:
            for j in range(target, num - 1, -1):
                if dp[j - num]:
                    dp[j] = True
        

        return dp[target]

        
