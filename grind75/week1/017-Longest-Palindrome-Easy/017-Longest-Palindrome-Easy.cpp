// Problem link: https://leetcode.com/problems/longest-palindrome/description/

class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_set<char> palset;
        int output = 0;

        for(char c : s)
        {
            if(palset.find(c) != palset.end())
            {
                output += 2;
                palset.erase(c);

            }
            else
            {
                palset.insert(c);
            }
        }

        if (palset.empty())
        {
            return output;
        }
        else
        {
            return output + 1;
        }

        
    }
};


