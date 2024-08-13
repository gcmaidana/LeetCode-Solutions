# Question link: https://leetcode.com/problems/backspace-string-compare/

# Stack could be one approach, but there's a way to solve it in O(1) spacel like this

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_index = len(s) - 1 
        t_index = len(t) - 1
        sBack = 0 
        tBack = 0 

        while s_index >= 0 or t_index >= 0:
            char_s = char_t = None

            while char_s is None and s_index >= 0:
                if s[s_index] == "#":
                    sBack += 1
                elif sBack > 0:
                    sBack -= 1
                else:
                    char_s = s[s_index]
                s_index -= 1

            while char_t is None and t_index >= 0:   
                if t[t_index] == "#":
                    tBack += 1
                elif tBack > 0:
                    tBack -= 1
                else:
                    char_t = t[t_index]
                t_index -= 1
            
            # compare the values
            if char_s != char_t:
                return False
        
        return True


        
