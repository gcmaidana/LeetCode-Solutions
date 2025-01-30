# Question link: https://leetcode.com/problems/valid-parentheses/

# Notes
# This is an O(n) solution since pop() and appending to list are O(1) operations
# https://wiki.python.org/moin/TimeComplexity

class Solution(object):
    def isValid(self, s):
        error = False
        my_stack = []
        for char in s:
            if char == '(' or char == '[' or char == "{":
                my_stack.append(char)

            elif char == ')':
                if not my_stack:
                    error = True
                    break
                element_before = my_stack.pop()
                if '(' != element_before:
                    error = True

            elif char == ']':
                if not my_stack:
                    error = True
                    break
                element_before = my_stack.pop()
                if '[' != element_before:
                    error = True

            elif char == '}':
                if not my_stack:
                    error = True
                    break
                element_before = my_stack.pop()
                if '{' != element_before:
                    error = True

        

        if my_stack or error == True:
            return False

        return True
         

# A more optimal solution I encountered using a hashmap, much more readable and easy to understand

class Solution:
    def isValid(self, s: str) -> bool:
        brackets = { '(' : ')', '{' : '}', '[' : ']'}
        stack = []

        for char in s:
            if char in brackets:
                stack.append(char)
            else:
                if len(stack) == 0 or char != brackets[stack.pop()]:
                    return False

        return len(stack) == 0


        
