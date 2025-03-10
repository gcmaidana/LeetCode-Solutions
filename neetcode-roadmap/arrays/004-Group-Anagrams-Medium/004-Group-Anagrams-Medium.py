# Problem link: https://leetcode.com/problems/group-anagrams/description/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sortMap = {}
        ans = []
        
        for word in strs:
            sorted_key = ''.join(sorted(word)) # sorted(word) is a list of characters, so must join them
            if sorted_key not in sortMap:
                sortMap[sorted_key] = [word] # store word in a list (not just a str)
            else:
                sortMap[sorted_key].append(word)
        
        # group like this:
        # eat => a e t
        # tea => a e t
        # etc

        for k, v in sortMap.items():
            ans.append(v)

        return ans
        
