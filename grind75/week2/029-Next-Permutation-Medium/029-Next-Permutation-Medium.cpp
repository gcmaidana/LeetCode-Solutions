// link: https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        Let's think about what we do with 3 different scenarios

        Increasing order, e.g. 1 2 3
        ans: 1 3 2

        Decreasing order, e.g. 3 2 1 ~ no next larger permutation, so find smallest (reverse), 
        ans: 1 2 3


        Mixed order, e.g. 1 3 4 9 7 5
        We need to formulaic-ly solve this by thinking of how to handle this

        Step 1.) From right to left, find where nums[i] < nums[i + 1]
        Index 2, since 4 < 9

        Step 2.) Set a different pointer at end of array, call it j, and compare nums[i] to nums[j],
        if nums[j] > nums[i], we can do a swap. 5 > 4

        REMEMBER: find the smallest permutation that is 
        greater than the current one..

        So now after the swap we have:
        1 3 5 9 7 4

        Now we reverse the array from i + 1 to the end of array so we get:
        1 3 5 4 7 9

        This algorithm will handle the increasing order by swapping the last 2,
        the decreasing order by reversing the whole thing,
        and the mixed order case by formulaic-ly and algorithmically handling
        what it needs to as described above!
        */

        int i = nums.size() - 2;

        // Find the first position from the right where nums[i] < nums[i + 1].
        // We keep moving left while the numbers are in decreasing order.
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If we found a valid pivot:
        // Find the smallest number from the right that is greater than nums[i],
        // then swap them.
        if (i >= 0) {
            int j = nums.size() - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        // Reverse everything after i.
        // If i == -1, this reverses the entire array,
        // which handles the case where the array is completely decreasing.
        reverse(nums.begin() + i + 1, nums.end());
    }
};
