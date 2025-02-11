# Question link: https://leetcode.com/problems/majority-element/description/
# YT Link: https://www.youtube.com/watch?v=7pnhv842keE
# YT Link: https://www.youtube.com/watch?v=M1IL4hz0QrE

# I used a hashmap to track the number of occurences of a particular number in a list and I returned whichever appears more than n / 2
# I don't think there can be more than 1 answer so we won't run into any problems


# My solution
class Solution:
    def majorityElement(self, nums: List[int]) -> int:        
        c = Counter(nums)
        size = len(nums) // 2

        for key, value in c.items():
            if value > size:
                return key
        
# Solution 2 - Solution with linear time complexity and O(1) space, though this solution is hard to come up on your own, it's the Boyer-Moore Algorithm
# Check the video for a visualization if you don't understand this solution
class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        majority_num = 0
        counter = 0


        for number in nums:
            if counter == 0:
                majority_num = number
                counter += 1
            elif majority_num == number:
                counter += 1
            else:
                counter -= 1
        return majority_num
