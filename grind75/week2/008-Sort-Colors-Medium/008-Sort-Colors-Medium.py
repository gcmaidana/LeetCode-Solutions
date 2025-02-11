# Problem link: https://leetcode.com/problems/sort-colors/

# Two pass, bucket sort (less efficient) solution

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        # O(2n)
        zero = one = two = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                zero += 1
            elif nums[i] == 1:
                one += 1
            else:
                two += 1 
            
        
        for i in range(len(nums)):
            if zero > 0:
                nums[i] = 0
                zero -= 1
            elif one > 0:
                nums[i] = 1
                one -= 1
            else:
                nums[i] = 2



# One pass (most efficient solution), Dutch National Flag Problem

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        l, r = 0, len(nums) - 1
        i = 0
        
        while i <= r:
            if nums[i] == 0:
                nums[l], nums[i] = nums[i], nums[l]
                l += 1
            elif nums[i] == 2:
                nums[r], nums[i] = nums[i], nums[r]
                r -= 1
                i -= 1 # dont want to increment i below in this case
            i += 1  # reason we dont put this in the if is because of infinite loop when nums[i] == 1

     
            
        



