// Problem link: https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majorityNum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (count == 0)
            {
                majorityNum = num;
                count += 1;
            }
            else if(majorityNum == num)
            {
                count += 1;
            }
            else
            {
                count -= 1;
            }
        }
        return majorityNum;
    }
};
