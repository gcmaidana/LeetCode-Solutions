# Question link: https://leetcode.com/problems/3sum/

# This problem is difficult to explain, but basically sorting the numbers helps us achieve our target more easily because we can shift left or right 
# for our pointer depending on if your given answer so far is less than or greater than the target when comparing the two
# This is a good problem that deals with that technique in the most basic terms: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
    
    
        for index, num in enumerate(nums):

            # if num is positive, no addition will make the number position (numbers to right are more positive because we sorted)
            if num > 0:
                break

            elif index > 0 and num == nums[index - 1]: 
                continue
            
            l, r = index + 1, len(nums) - 1
            while l < r:
                threeSum = num + nums[l] + nums[r]
                if threeSum == 0: # 
                    ans.append((num, nums[l], nums[r]))
                    l += 1
                    r -= 1 
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                    while nums[r] == nums[r + 1] and l < r:
                        r -= 1
                elif threeSum < 0:
                    l += 1
                else:
                    r -= 1


        return ans
        
