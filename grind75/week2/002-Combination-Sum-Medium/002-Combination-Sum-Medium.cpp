// Problem link: https://leetcode.com/problems/combination-sum/
// This problem will require recursion, so we will handle the different indexes in the array and do
// a "pick or don't pick" approach (similar to House Robber or other similar types of problems).
// So we have to handle each index and decide whether to pick it or not, and if we do, how many TIMES we pick it

class Solution {
public:

    void dfs(int i, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& tmpArray)
    {
        if(i == arr.size())
        {
            if(target == 0) { ans.push_back(tmpArray); } // Automatically creates a copy of tmpArray 
            return;
        }
        if(arr[i] <= target)
        {
            tmpArray.push_back(arr[i]);
            dfs(i, arr, target - arr[i], ans, tmpArray);
            tmpArray.pop_back();
        }

        dfs(i + 1, arr, target, ans, tmpArray);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {   
        vector<vector<int>> ans; 
        vector<int> tmpArray; 
        dfs(0, candidates, target, ans, tmpArray);
        return ans;
    }
};
