// Problem link: https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort intervals by the starting value of each interval
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        // Output vector to store merged intervals
        std::vector<std::vector<int>> output;
        output.push_back(intervals[0]);

        // Iterate through the sorted intervals
        for (size_t i = 1; i < intervals.size(); ++i) {
            int lastEnd = output.back()[1];  // End value of the most recent interval in the output
            int start = intervals[i][0];
            int end = intervals[i][1];

            // If the current interval overlaps with the last one in the output, merge them
            if (start <= lastEnd) {
                output.back()[1] = std::max(lastEnd, end);
            } else {
                // Otherwise, add the current interval to the output
                output.push_back({start, end});
            }
        }

        return output;
        
    }
};
