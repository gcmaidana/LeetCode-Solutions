// Problem link: https://leetcode.com/problems/valid-parentheses/


class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapping = 
        { 
            {'(', ')'}, 
            {'[', ']'}, 
            {'{', '}'}
        };
        std::stack<char> charStack{}; 

        for(char c : s) 
        {
            if (mapping.count(c)) 
            {
                charStack.push(c);
            }
            else 
            {
                if (charStack.empty() || mapping[charStack.top()] != c)
                {
                    return false;
                }
                charStack.pop();
            }
        }
        return charStack.empty();
    }
};
