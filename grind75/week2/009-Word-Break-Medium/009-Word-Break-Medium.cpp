// Problem: https://leetcode.com/problems/word-break/
// Approach:
// Start at the empty string (dp[0]) and find words that can be built from there.
// Mark the ending index as true in the dp array.
// If at the end, that index (dp[s.length()]) is true, it means the string be can be built
// using words from the wordDict. Otherwise, return false

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // base case: empty string is always segmentable

        // Use unordered_set for O(1) lookup
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());

        // Track the maximum word length to avoid unnecessary substring checks
        int maxWordLen = 0;
        for(const string& word : wordDict)
        {
            if(word.length() > maxWordLen)
            {
                maxWordLen = word.length();
            }
        }

        // DP approach
        for(int i = 0; i < n; i++)
        {
            if(dp[i])
            {
                // Only check substrings up to maxWordLen to avoid unnecessary checks
                for(int j = i + 1; j < min(i + maxWordLen + 1, n + 1); j++)
                {
                    if(wordDictSet.find(s.substr(i, j-i)) != wordDictSet.end())
                    {
                        dp[j] = true;
                    }
                }
            }
        }

        return dp[n];

    }
};
