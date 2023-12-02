# Question link: https://leetcode.com/problems/contains-duplicate/

# This is a simple approach using a set
# Basically if a number is already in the set, then we're encountering it a 2nd time, so we just return true in that case

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:

        hset = set()

        for i in nums:
            if i in hset:
                return True
            hset.add(i)
        return False
        
        
