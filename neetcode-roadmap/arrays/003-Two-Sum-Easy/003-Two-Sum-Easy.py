# Problem link: https://leetcode.com/problems/two-sum/
# Notes:
# This is O(n) because I'm just processing the elements of the input list once, and
# regarding the dict, "k in d" is O(1) on average.

class Solution(object):
    def twoSum(self, nums, target):
        my_map = {}

        for index, element in enumerate(nums):
            if target - element in my_map:
                return (my_map[target - element], index)
            else:
                my_map[element] = index
