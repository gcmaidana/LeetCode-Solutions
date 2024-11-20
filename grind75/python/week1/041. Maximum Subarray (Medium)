# Question link: https://leetcode.com/problems/maximum-subarray/description/

# Kadane's algorithm
# Even for a test case like this: [-5, -3, -1]
# It would work because you're adding the sum of the current number and checking it's greater than the max seen so far, you're only resetting the sum to 0 the next time around if the sum is less than 0.

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = float('-inf')
        curSum = 0

        for num in nums:
            if curSum < 0:
                curSum = 0
            curSum += num
            maxSum = max(maxSum, curSum)
        return maxSum
