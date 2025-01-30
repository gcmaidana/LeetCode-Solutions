// Problem link: https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the input array
        vector<vector<int>> ans;

        for (int index = 0; index < nums.size(); ++index) {
            int num = nums[index];

            // If the current number is positive, we can stop (no positive sum can be zero)
            if (num > 0) break;

            // Skip duplicates for the current index
            if (index > 0 && nums[index] == nums[index - 1]) continue;

            int l = index + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int threeSum = num + nums[l] + nums[r];

                if (threeSum == 0) {
                    ans.push_back({num, nums[l], nums[r]});
                    ++l;
                    --r;

                    // Skip duplicates for `l`
                    while (l < r && nums[l] == nums[l - 1]) ++l;

                    // Skip duplicates for `r`
                    while (l < r && nums[r] == nums[r + 1]) --r;

                } else if (threeSum < 0) {
                    ++l; // Move the left pointer to increase the sum
                } else {
                    --r; // Move the right pointer to decrease the sum
                }
            }
        }

        return ans;
    }
};
