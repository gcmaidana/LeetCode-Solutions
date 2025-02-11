// Problem link: https://leetcode.com/problems/maximum-subarray/ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = std::numeric_limits<int>::min();
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if (curSum < 0) { curSum = 0; }

            curSum += nums[i];
            maxSum = std::max(maxSum, curSum);
        }
        
        return maxSum;
        
    }
};
