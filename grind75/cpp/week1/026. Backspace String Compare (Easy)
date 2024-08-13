// Problem link: https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sIndex = s.length() - 1;
        int tIndex = t.length() - 1;
        int sBack = 0;
        int tBack = 0;

        while(sIndex >= 0 || tIndex >= 0)
        {
            char charS = '0';
            char charT = '0';

            while (charS == '0' && sIndex >= 0)
            {
                if(s[sIndex] == '#')
                {
                    sBack += 1;
                }
                else if(sBack > 0)
                {
                    sBack -= 1;
                }
                else
                {
                    charS = s[sIndex];
                }
                sIndex -= 1;
            }
            while (charT == '0' && tIndex >= 0)
            {
                if(t[tIndex] == '#')
                {
                    tBack += 1;
                }
                else if(tBack > 0)
                {
                    tBack -= 1;
                }
                else
                {
                    charT = t[tIndex];
                }
                tIndex -= 1;
            }
            if (charS != charT) 
            {
                return false;
            }

        } // end of while loop

        return true;
    }
};
