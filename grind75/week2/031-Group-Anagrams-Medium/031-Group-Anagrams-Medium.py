# link: https://leetcode.com/problems/group-anagrams/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        # notes
        # Output appears to be An array of array of strings

        # hashmap where the key is the freq count of each letter, the value is the word
        # so group values with the same keys
        anagramMap = defaultdict(list)
        
        for s in strs:
            count = [0] * 26
            for char in s:
                count[ord(char) - ord('a')] += 1

            key = tuple(count) # lists cannot be keys so count must be a tuple
            anagramMap[key].append(s)
        
        
        return list(anagramMap.values()) # already grouped, but we must return a list of lists
                
