// link: https://leetcode.com/problems/subsets/


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
   {
        vector<vector<int>> ans;
        vector<int> arr;
        backtrack(0, nums, arr, ans);
        return ans;
    }

private:
    void backtrack(int i, vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans) 
{
        if (i == nums.size()) 
        {
            ans.push_back(arr);
            return;
        }

        // Take
        arr.push_back(nums[i]);
        backtrack(i + 1, nums, arr, ans);

        // Don't take (backtrack)
        arr.pop_back();
        backtrack(i + 1, nums, arr, ans);
    }
};
