# Question link: https://leetcode.com/problems/missing-number/

# Use XOR to "cancel out" each number that appears in the nums and the numbers from 0 up to and including the length of the array
# For example if our input is [0, 1, 3] we want to XOR that with [0,1, 2, 3] and we will get 2
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = 0

        for i in nums:
            res ^= i

        for i in range(len(nums)+ 1 ):
            res ^= i
        
        return res

        

# An alternative solution is take the sum from 0 up to and including the length of the array and subtract the sum of the input array and we will be left with the missing number
# For example, if our input array was [0, 1, 3] we would do
#
# (0 + 1 + 2 + 3) - (0 + 1 + 3) = 2

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = len(nums)

        for i in range(len(nums)):
            res += (i - nums[i])

        return res

# alternatively can write it like this if easier to read
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sumN = 0
        for i in range(len(nums) + 1):
            sumN += i
        return sumN - sum(nums)
        
