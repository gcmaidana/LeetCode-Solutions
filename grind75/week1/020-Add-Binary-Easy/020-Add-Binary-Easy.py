# Question link: https://leetcode.com/problems/add-binary/

class Solution:
    def addBinary(self, a: str, b: str) -> str:

        pointerA = len(a) - 1
        pointerB = len(b) - 1

        carry = 0
        ans = ""

        while pointerA >= 0 or pointerB >= 0:
            digitA = int(a[pointerA]) if pointerA >= 0 else 0
            digitB = int(b[pointerB]) if pointerB >= 0 else 0
            sumDigit = digitA + digitB + carry
            ans += str(sumDigit % 2)
            carry = sumDigit // 2
            pointerA -= 1
            pointerB -= 1
        
        if carry > 0:
            ans += "1"
        
        return ans[::-1]



