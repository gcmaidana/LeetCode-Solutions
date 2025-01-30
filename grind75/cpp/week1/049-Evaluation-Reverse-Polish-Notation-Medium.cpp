// Problem link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int s1 = stack.top();
                stack.pop();
                int s2 = stack.top();
                stack.pop();
                if(tokens[i] == "+")
                {
                    int ans = s1 + s2;
                    stack.push(ans);
                }
                else if(tokens[i] == "-")
                {
                    int ans = s2 - s1;
                    stack.push(ans);
                }
                else if(tokens[i] == "*")
                {
                    int ans = s1 * s2;
                    stack.push(ans);
                }
                else
                {
                    int ans = s2 / s1; 
                    stack.push(ans);
                }
            }
            else
            {
                stack.push(std::stoi(tokens[i]));
            }
        }

        int ans = stack.top();
        stack.pop();
        return ans;
    }
};
