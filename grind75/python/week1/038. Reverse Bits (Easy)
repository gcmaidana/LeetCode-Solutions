# Question link: https://leetcode.com/problems/reverse-bits/description/

class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0

        for i in range(32):
            bit = (n >> i) & 1
            res = res | (bit << (31 - i))
        return res


# This solution is doing the exact same thing as the one above, but I personally find it more readable and doing the bit shifting by 1 rather by i amount each time

class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for _ in range(32):
            ans = ans << 1
            bit = n & 1
            ans = ans | bit
            n = n >> 1
        return ans
        
        
