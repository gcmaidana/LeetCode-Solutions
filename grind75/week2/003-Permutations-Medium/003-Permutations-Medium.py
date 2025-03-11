# Problem link: https://leetcode.com/problems/permutations/
# For n element, there are n! permutations, so for n = 3 e.g. [1, 2, 3], 3! = 6 permutations
# Initially I knew a decision tree would be a good way to conceptually think of an approach, but I
# got lost on how to actually implement such a decision tree through code via backtracking, etc



# we have O(n!) for generating all permutations
# However, the check if x not in perm_arr is an O(n) operation in Python (it has to scan the array)
#So each recursive call takes O(n²) time: O(n) iterations with an O(n) check in each
# This results in O(n! * n) total time complexity
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        # number of permutations = n! where n = len(nums)

        # base case
        if len(nums) == 1:
            # single element still must be returned as an array of arrays
            return [nums.copy()] 

        ans = []
        perm_arr = []

        def bt():

            if len(perm_arr) == len(nums):
                ans.append(perm_arr.copy())
                return

            for x in nums:
                if x not in perm_arr:
                    perm_arr.append(x)
                    bt()
                    perm_arr.pop()
        
        bt()
        return ans


# Slightly, faster lookup O(n!) solution now. The trade off is we use extra space

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        # number of permutations = n! where n = len(nums)

        # base case
        if len(nums) == 1:
            # single element still must be returned as an array of arrays
            return [nums.copy()] 

        ans = []
        used = set()

        def bt(perm_arr):

            if len(perm_arr) == len(nums):
                ans.append(perm_arr.copy())
                return

            for x in nums:
                if x not in used:
                    used.add(x)
                    perm_arr.append(x)
                    bt(perm_arr)
                    perm_arr.pop()
                    used.remove(x)
        
        bt([])
        return ans


# The best approach, swap-based approach!

# Draw out an array and walk through this code step-by-step and
# the algorithm will make more sense

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        ans = []
        def bt(start_index):
            if start_index == len(nums):
                ans.append(nums.copy())
                return
            
            for i in range(start_index, len(nums)):
                # Swap elements
                nums[start_index], nums[i] = nums[i], nums[start_index]

                # recurse
                bt(start_index + 1)

                # Swap back to original state
                nums[start_index], nums[i] = nums[i], nums[start_index]

        bt(0)
        return ans
        

