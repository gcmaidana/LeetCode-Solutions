// Problem link: https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) 
        {
            // int mid = (l + r) / 2; -> l + r can cause overflow in extreme edge cases
            // good visual: https://www.youtube.com/watch?v=_eS-nNnkKfI

            int mid = l + (r - l) / 2;       


            if (target < nums[mid])
            {
                r = mid - 1;
            }
            else if(target > nums[mid]) 
            {
                l = mid + 1;
            }
            else 
            {
                return mid;
            }
        }

        return -1;
    }
};
