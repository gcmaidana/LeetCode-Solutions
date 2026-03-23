# link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        # cannot make anagrams if len of p is greater than len of s
        if len(s) < len(p):
            return []

        p_map = collections.Counter(p)
        s_map = {}
        ans = []
        for i in range(len(s)):
            if s[i] not in  s_map:
                s_map[s[i]] = 1
            else:
                s_map[s[i]] += 1
            
            if i >= len(p):
                if s_map[s[i - len(p)]] == 1:
                    del s_map[s[i - len(p)]]
                else:
                    s_map[s[i - len(p)]] -= 1

            if p_map == s_map:
                ans.append(i - len(p) + 1)

        return ans

        
