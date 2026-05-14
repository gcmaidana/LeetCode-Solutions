// link: https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> my_stack;
        vector<int> ans(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) 
        {
            while (!my_stack.empty() && temperatures[i] > temperatures[my_stack.top()]) 
            {
                int idx = my_stack.top();
                my_stack.pop();
                ans[idx] = i - idx;
            }
            my_stack.push(i);
        }

        return ans;
    }
};
