# Question link: https://leetcode.com/problems/product-of-array-except-self/description/

# Basically everything to left of an index and everything to the right of an index multiplied together gives the correct answer for a given index
# To simulate this, we maintain an ans array to multiple everything to the left of a given index in nums and then loop back about in reverse
# for everything to the right of an index in nums, but all of this calculation is stored in ans
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [1] * len(nums)
        
        prefix = 1
        for i in range(len(nums)):
            ans[i] = ans[i] * prefix
            prefix = nums[i] * prefix
        
        postfix = 1
        for i in reversed(range(len(nums))):
            ans[i] = ans[i] * postfix
            postfix = nums[i] * postfix
        

        return ans
        

        
