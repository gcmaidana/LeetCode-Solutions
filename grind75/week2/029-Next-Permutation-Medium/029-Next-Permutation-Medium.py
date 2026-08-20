class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Let's think about what we do with 3 different scenarios
        # Increasing order, e.g. 1 2 3
        # ans: 1 3 2

        # Decreasing order, e.g. 3 2 1 ~ no next larger permutation, so find smallest (reverse), 
        # ans: 1 2 3


        # Mixed order, e.g. 1 3 4 9 7 5
        # We need to formulaic-ly solve this by thinking of how to handle this
        # Step 1.) From right to left, find where nums[i] < nums[i + 1]
        # Index 2, since 4 < 9
        # Step 2.) Set a different pointer at end of array, call it j, and compare nums[i] to nums[j],
        # if nums[j] > nums[i], we can do a swap. 5 > 4 REMEMBER: find the smallest permutation that is 
        # greater than the current one.. So now after the swap we have
        # 1 3 5 9 7 4
        # Now we reverse the array from i + 1 to the end of array so we get
        # 1 3 5 4 7 9

        # This algorithm will handle the increasing order by swapping the last 2
        # The decreasing order by reversing the whole thing
        # The mixed order case by formulaic-ly and algorithmically handling what it needs to as described above!

        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            self.swap(nums, i, j)
        self.reverse(nums, i + 1)


    def reverse(self, nums, start):
        i, j = start, len(nums) - 1
        while i < j:
            self.swap(nums, i, j)
            i += 1
            j -= 1

    def swap(self, nums, i, j):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp
