// Problem link: https://leetcode.com/problems/combination-sum/
// This problem will require recursion, so we will handle the different indexes in the array and do
// a "pick or don't pick" approach (similar to House Robber or other similar types of problems).
// So we have to handle each index and decide whether to pick it or not, and if we do, how many TIMES we pick it

class Solution {
public:

    void dfs(int i, vector<vector<int>>& ans, vector<int>& candidates, vector<int>& tmpComboArray, int remaining)
    {
        // if out of bounds or combo array exceeds target, return
        if(i >= candidates.size() || remaining < 0)
        {
            return;
        }

        // combination sums up to target, add it to ans and return
        if(remaining == 0)
        {
            ans.push_back(tmpComboArray);   
            return;
        }

        // recursively go into the same index and change remaining to account for the number
        // we added
        tmpComboArray.push_back(candidates[i]);
        dfs(i, ans, candidates, tmpComboArray, remaining - candidates[i]);

        // exit call stack, pop from combo array and add the next index
        tmpComboArray.pop_back();
        dfs(i + 1, ans, candidates, tmpComboArray, remaining);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {   
        vector<vector<int>> ans; 
        vector<int> tmpComboArray; 
        dfs(0, ans, candidates, tmpComboArray, target);
        return ans;
    }
};
