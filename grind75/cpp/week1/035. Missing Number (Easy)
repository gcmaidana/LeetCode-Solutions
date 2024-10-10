// Problem link: https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumN = 0;
        for(int i = 0; i <= nums.size(); i++)
        {
            sumN += i;
        }

        return sumN - std::accumulate(nums.begin(), nums.end(), 0);
    }
};

// XOR solution
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;

        for(int num : nums)
        {
            ans = ans ^ num;
        }

        for(int i = 0; i <= nums.size(); i++)
        {
            ans = ans ^ i;
        }

        return ans;
        
    }
};
