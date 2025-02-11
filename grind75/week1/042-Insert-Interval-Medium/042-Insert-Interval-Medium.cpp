// Problem link: https://leetcode.com/problems/insert-interval/

 class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Edge case: if intervals are empty
        if (intervals.empty()) {
            return { newInterval };
        }

        const int start = 0;
        const int end = 1;
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            // New interval is to the right of the current interval
            if (intervals[i][end] < newInterval[start]) {
                res.push_back(intervals[i]);
            } 
            // New interval is to the left of the current interval
            else if (intervals[i][start] > newInterval[end]) {
                res.push_back(newInterval);
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            } 
            // There's an overlap
            else {
                newInterval[start] = min(intervals[i][start], newInterval[start]);
                newInterval[end] = max(intervals[i][end], newInterval[end]);
            }
        }

        // Accounts for edge cases
        res.push_back(newInterval);

        return res;
    }
};
