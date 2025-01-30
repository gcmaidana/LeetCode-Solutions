// Problem link: https://leetcode.com/problems/valid-anagram/description/

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
