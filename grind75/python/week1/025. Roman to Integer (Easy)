# Question link : https://leetcode.com/problems/roman-to-integer/description/

class Solution:
    def romanToInt(self, s: str) -> int:
        romanMap = { 'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' : 1000}
        count = 0

        for i in range(len(s)):
            if i + 1 < len(s) and romanMap[s[i]] < romanMap[s[i + 1]]:
                count -= romanMap[s[i]] 
            else:
                count += romanMap[s[i]]
        return count

# Ex: IV -> -1 + 5 -> 4
#     VI -> 1 + 5 -> 6
