# Problem link: https://leetcode.com/problems/permutations/
# For n element, there are n! permutations, so for n = 3 e.g. [1, 2, 3], 3! = 6 permutations
# Initially I knew a decision tree would be a good way to conceptually think of an approach, but I
# got lost on how to actually implement such a decision tree through code via backtracking, etc

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        def recurPermutate(nums, ds, ans, freq):
            if len(ds) == len(nums):
                ans.append(ds.copy())
                return

            for i in range(len(nums)):
                if not freq[i]:
                    freq[i] = True
                    ds.append(nums[i])
                    recurPermutate(nums, ds, ans, freq)
                    ds.pop()
                    freq[i] = False



        ans = []
        ds = []
        freq = [False] * len(nums)
        recurPermutate(nums, ds, ans, freq)
        return ans

        


