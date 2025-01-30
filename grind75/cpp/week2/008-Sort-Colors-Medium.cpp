// Problem link: https://leetcode.com/problems/sort-colors/description/

// One pass solution

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;

        while(i <= r)
        {
            if(nums[i] == 0)
            {
                int tmp = nums[l];
                nums[l] = nums[i];
                nums[i] = tmp;
                l += 1;
            }
            else if(nums[i] == 2)
            {
                int tmp = nums[r];
                nums[r] = nums[i];
                nums[i] = tmp;
                r -= 1;
                i -= 1;
            }

            i += 1;
        }
        
    }
};
