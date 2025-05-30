# problem link: https://leetcode.com/problems/string-to-integer-atoi/

class Solution:
    def myAtoi(self, s: str) -> int: # str -> 32 bit signed int

        # Strip whitespace, it's possible the entire string is whitespace, in the case
        # return 0
        i = 0
        n = len(s)
        while i < n and s[i] == ' ':
            i += 1

        # Check if number is positive or negative
        sign = 1
        if i < n and s[i] == "-":
            sign = -1
            i += 1
        elif i < n and s[i] == "+":
            i += 1

        # Handle the digits
        result = 0
        while i < n and s[i].isdigit():
            result = result * 10 + int(s[i])
            i += 1

            # ex: 445
            # we go from 0
            # to 
            # 0 * 10 + 4 = 4
            # then 4 * 10 + 4 = 44
            # then 44 * 10 + 5 = 445 

        # Check if in range, if not, clamp it
        result = result * sign

        if result < -2**31:
            return -2**31
        elif result > 2**31 - 1:
            return 2**31 - 1
        else:
            return result

    
     







        return num


        # remove leading whitespace
        # ignore non-int characters
        # clamp to boundary if out of range
