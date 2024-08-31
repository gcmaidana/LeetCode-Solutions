# Problem link: https://leetcode.com/problems/combination-sum/
# This problem will require recursion, so we will handle the different indexes in the array and do
# a "pick or don't pick" approach (similar to House Robber or other similar types of problems).
# So we have to handle each index and decide whether to pick it or not, and if we do, how many TIMES we pick it

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []

        def dfs(i, arr, target, ans, tmpArray):

            if i == len(arr):
                if target == 0:
                    ans.append(tmpArray.copy()) # avoid dereferencing issues
                return
            
            if arr[i] <= target:
                tmpArray.append(arr[i])
                dfs(i, arr, target - arr[i], ans, tmpArray) // pick
                tmpArray.pop()
            
            dfs(i + 1, arr, target, ans, tmpArray) // not pick

        tmpArray = []
        dfs(0, candidates, target, ans, tmpArray)

        return ans

        
