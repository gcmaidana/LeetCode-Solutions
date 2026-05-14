// link: https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> myStack;
        vector<int> ans(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!myStack.empty() && temperatures[i] > temperatures[myStack.top()])
            {
                int idx = myStack.top();
                myStack.pop();
                ans[idx] = i - idx;
            }
            myStack.push(i);
        }

        return ans;
    }
};
