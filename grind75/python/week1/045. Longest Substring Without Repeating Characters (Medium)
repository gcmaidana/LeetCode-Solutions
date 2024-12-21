# Question link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

# This just a classic sliding window problem, not to difficult to comprehend

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = r = 0
        mySet = set()
        count = 0

        while r < len(s):
            if s[r] not in mySet:
                mySet.add(s[r])
                r += 1
                count = max(count, len(mySet))
            
            else:
                mySet.remove(s[l])
                l += 1

        
        return count
        

// Or if you don't want to manually increment pointers

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        l = 0
        count = 0
        mySet = set()

        for r in range(len(s)):
            while s[r] in mySet:
                mySet.remove(s[l])
                l += 1
            mySet.add(s[r])
            count = max(count, r - l + 1)
        
        return count
        

        


        
