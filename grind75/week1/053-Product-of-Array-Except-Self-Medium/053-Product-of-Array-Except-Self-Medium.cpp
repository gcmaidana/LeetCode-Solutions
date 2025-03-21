// Problem link: https://leetcode.com/problems/product-of-array-except-self/description/

// Basically everything to left of an index and everything to the right of an index multiplied together gives the correct answer for a given index
// To simulate this, we maintain an ans array to multiple everything to the left of a given index in nums and then loop back about in reverse
// for everything to the right of an index in nums, but all of this calculation is stored in ans
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;
        for(int i = 0; i < n; i++)
        {
            ans[i] = ans[i] * prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * postfix;
            postfix = postfix * nums[i];
        }

        return ans;

        
    }
};
