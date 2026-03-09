# link: https://leetcode.com/problems/container-with-most-water/
class Solution:
    def maxArea(self, height: List[int]) -> int:

        l = 0
        r = len(height) - 1
        water = 0
        
        # compare two heights, take the min, multiply by distance, store area if its the largest
        # seen so far
        # move left and right pointer depending on which is smaller (we want most water, so we want bigger heights)

        while l != r:
            water = max(water, (r-l) * min(height[l], height[r]))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return water
