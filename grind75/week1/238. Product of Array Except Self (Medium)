# Question link: https://leetcode.com/problems/product-of-array-except-self/description/

# It would be easy to create a prefix and postfix array to do this problem. The tricky part of this problem is using O(1) space (the output array doesn't count as extra space though)
# The idea is to use the answer array to do the prefix, work backwards and compute the result using postfix, and the prefix values in the array

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1] * len(nums)
        prefix = 1
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]
        postfix = 1
        for i in reversed(range(len(nums))):
            res[i] *= postfix  
            postfix *= nums[i]

        return res



        
