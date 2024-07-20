# Question link: https://leetcode.com/problems/binary-search/


# Notes: Before I looked at any solution, I understood that the way to solve this 
# problem was to cut the list in half and see if my target is above or below the halfway point
# and keep doing that until I either find the target and return its index or 
# can't go any further and know the target doesn't exist, so I return -1.
# I know this is a good approach because the list is sorted.

# However, I had difficulty taking this logic and applying it to the problem in code.
# I had a solution but it was overly complicated and not entirely correct.

# Additionally, I also didn't know that // finds the floor of the quotient instead of the floating point!

# Also, one little note, if we had a very large nums list, we could have an over flow error. This isn't really
# a concern in Python, but it could be if we were in something like Java or C++. The point where it could overflow
# is when we add the left and right pointers.. in that case, we could prevent that by doing m = l + ((r-l) // 2)
# It's unlikely that would be asked in an inteview, but if it is, it's important to know the proper approach.

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1

        while(l <= r):
            mid = (l + r) // 2

            if nums[mid] > target:
                r = mid - 1
            elif nums[mid] < target:
                l = mid + 1
            else:
                return mid
         
        return -1

            

            
