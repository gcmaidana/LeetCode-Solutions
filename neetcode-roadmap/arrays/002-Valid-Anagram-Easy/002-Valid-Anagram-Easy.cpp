// Problem link: https://leetcode.com/problems/valid-anagram/description/

// "What if the inputs contain Unicode characters? How would you adapt your solution to such a case?"
// Hashmap is best to address this issue unlike an array of 26 characters

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length()) {return false;}
    
            std::unordered_map<char, int> wordMap;
    
            for(int i = 0; i < s.length(); i++)
            {
                if(wordMap.count(s[i]))
                {
                    wordMap[s[i]] += 1;
                }
                else
                {
                    wordMap[s[i]] = 1;
                }
            }
    
            for(int i = 0; i < t.length(); i++)
            {
                if(!wordMap.count(t[i]) || wordMap[t[i]] == 0)
                {
                    return false;
                }
                else
                {
                    wordMap[t[i]] -= 1;
                }
            }
    
            return true;
        }
    };