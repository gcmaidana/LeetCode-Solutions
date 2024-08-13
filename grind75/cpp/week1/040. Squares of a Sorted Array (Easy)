// Problem link: https://leetcode.com/problems/squares-of-a-sorted-array/description/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        std::vector<int> ans;

        while(l <= r)
        {
            int left = nums[l] * nums[l];
            int right = nums[r] * nums[r];

            if(left > right)
            {
                ans.push_back(left);
                l += 1;
            }
            else
            {
                ans.push_back(right);
                r -= 1;
            }
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
