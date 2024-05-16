# Question link: https://leetcode.com/problems/palindrome-number/description/

# Reverse the number and compare the reversed number to x

class Solution:
    def isPalindrome(self, x: int) -> bool:

        if x < 0:
            return False

        dummy_x = x
        reversed_number = 0

        while dummy_x:
            reversed_number = reversed_number * 10 + dummy_x % 10
            dummy_x = dummy_x // 10
        
        return x == reversed_number
        
