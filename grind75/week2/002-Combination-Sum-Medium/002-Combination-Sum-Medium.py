# Problem link: https://leetcode.com/problems/combination-sum/
# This problem will require recursion, so we will handle the different indexes in the array and do
# a "pick or don't pick" approach (similar to House Robber or other similar types of problems).
# So we have to handle each index and decide whether to pick it or not, and if we do, how many TIMES we pick it

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        
        def bt(i, combo_arr, remaining):

            # base case
            # if index out of bounds or combo arr exceeds target, return
            if(i >= len(candidates) or remaining < 0):
                return
            
            # if combo arr adds up exactly to target, copy the combo array to ans array
            if(remaining == 0):
                ans.append(combo_arr.copy())
                return

            # if combo arr doesnt add up to target yet, lets keep adding the same number
            # recursively until we hit one of the if statements above
            # remaining > 0
            combo_arr.append(candidates[i])
            bt(i, combo_arr, remaining - candidates[i]) # pick same number

            # to backtrack, we pop the element we came back from and go to the next
            # index
            combo_arr.pop()
            bt(i + 1, combo_arr, remaining)
            


        bt(0, [], target)
        return ans
        
