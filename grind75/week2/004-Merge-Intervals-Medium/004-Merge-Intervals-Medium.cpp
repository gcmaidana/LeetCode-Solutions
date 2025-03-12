// Problem link: https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int start = 0;
        int end = 1;
        int prevStart = intervals[0][start];
        int prevEnd = intervals[0][end];

        for(int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][start] <= prevEnd)
            {
                prevEnd = std::max(prevEnd, intervals[i][end]);
            }
            else
            {
                ans.push_back({prevStart, prevEnd});
                prevStart = intervals[i][start];
                prevEnd = intervals[i][end];
            }

        }

        // Either we merge and don't append quite yet
        // or append but set the last one and not append it 
        //  in either case, we have an interval to append
        ans.push_back({prevStart, prevEnd});

        return ans;
        
    }
};
