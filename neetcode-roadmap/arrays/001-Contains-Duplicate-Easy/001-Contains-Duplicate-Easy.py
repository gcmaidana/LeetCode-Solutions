# Problem link: https://leetcode.com/problems/contains-duplicate/


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:

        s = set()

        for n in nums:
            if n in s:
                return True
            else:
                s.add(n)
        
        return False

# Solution with no extra space
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:

        nums.sort()

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return True
        return False
        
