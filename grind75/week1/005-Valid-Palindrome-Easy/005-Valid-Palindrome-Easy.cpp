// Problem link: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while(l < r)
        {
            if (!isAlphaNumeric(s[l]))
            {
                l += 1;
            }
            else if(!isAlphaNumeric(s[r]))
            {
                r -= 1;
            }
            else
            {
                auto left = s[l];
                auto right = s[r];
                if('A' <= left && left <= 'Z')
                {
                    left = left + 32;
                }
                if('A' <= right && right <= 'Z')
                {
                    right = right + 32;
                }

                if (left != right)
                {
                    return false;
                }

                l += 1;
                r -= 1;
            }
        }
        return true;
    }

    bool isAlphaNumeric(char c)
    {
        // built in function solution:
        // return std::isalnum(c);

        // manual implementation
        return ('A' <= c && c <= 'Z') ||
               ('a' <= c && c <= 'z') ||
               ('0' <= c && c <= '9');
    }
};

   

