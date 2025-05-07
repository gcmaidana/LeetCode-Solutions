# Problem link: https://leetcode.com/problems/word-break/

# slightly inefficient es
# Basically start at the empty string, and find the words that be built from there,
# mark ending index as true, keep doing the same process. If at the end, that index is true, it means
# there are words that can be used to from the string s, so it should return true, otherwise return false
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:

        dp = [False] * (len(s) + 1) 
        dp[0] = True # empty str can always be segmented
        wordDictSet = set(wordDict) # Use set for O(1) lookup

        for i in range(len(s)):
            if dp[i]:
                for j in range(i, len(s)):
                    if s[i:j+1] in wordDictSet:
                        dp[j + 1] = True

        
        return dp[-1]



# Optimal

def wordBreak(s, wordDict):
    word_set = set(wordDict)
    dp = [False] * (len(s) + 1)
    dp[0] = True
    
    for i in range(1, len(s) + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_set:
                dp[i] = True
                break
    
    return dp[len(s)]
