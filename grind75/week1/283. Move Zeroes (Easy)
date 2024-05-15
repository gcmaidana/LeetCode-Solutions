# Question link: https://leetcode.com/problems/move-zeroes/

# All non-zero values should end up on the left. So we start with a pointer on the left most position
# and when we encounter our first non-zero number, we place it at this position and add one to the variable
# so that now, the next non-zero number gets places into the new left position, etc, until we move all non-zero
# values into the left side of the list

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = 0
        r = 1
        while r < len(nums):
                if nums[l] == 0:
                    if nums[r] != 0:
                        nums[l], nums[r] = nums[r], nums[l]
                        l += 1
                        r = l + 1
                    else:
                        r += 1

                else:
                    l += 1
                    r = l + 1
        return nums



class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        left = 0
        for right in range(len(nums)):
            if nums[right] != 0:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1

