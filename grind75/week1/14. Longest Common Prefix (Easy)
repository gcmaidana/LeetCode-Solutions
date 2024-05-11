# Question link: https://leetcode.com/problems/longest-common-prefix/description/


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # some people sort the strings, i prefer not to do, it's likely not going to be allowed at an interview
        if len(strs) == 1:
            return strs[0]

        for i in range(len(strs[0])):
            char = strs[0][i]
            for word in range(1, len(strs)): # compares ALL char characters at once
                if i == len(strs[word]) or strs[word][i] != char: # out of bounds OR char not matching
                    return strs[0][:i] # slices from start of string up to but not including the index i
        
        return strs[0]
        

        

