# Problem link: https://leetcode.com/problems/word-break/

# Basically start at the empty string, and find the words that can be built from there
 # mark the ending index as true, keep doing the same process. If at the end, that index is true,
 # it means there are words that can be used from wordDict to form string s, so it should return true
 # otherwise return false
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        dp = [False] * (len(s) + 1) 
        dp[0] = True # empty str can always be segmented
        wordDictSet = set(wordDict) # Use set for O(1) lookup

        # When checking substrings to see if a substring in s is in wordDict,
        # we dont want to expand our substrings to exceed the length of the longest
        # word in wordDict, that is just inefficient and a waste of computation, so
        # lets keep track of the max word length in wordDict so we dont exceed this length
        # when checking substrings
        max_word_len = max(len(word) for word in wordDict) if wordDict else 0

        for i in range(len(s)):
            if dp[i]:
                for j in range(i, min(i + max_word_len, len(s))):
                    if s[i:j+1] in wordDictSet:
                        dp[j + 1] = True

        
        return dp[-1] # or alternatively, return dp[len(s)]
