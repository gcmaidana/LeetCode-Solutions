# problem link: https://leetcode.com/problems/merge-intervals/description/

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        # output is a list of list

        intervals.sort()

        start = 0
        end = 1
        ans = []
        prev = intervals[0]
        for interval in intervals[1:]:

            if interval[start] <= prev[end]:
                prev[end] = max(interval[end], prev[end])
            else:
                ans.append(prev)
                prev = interval
        
        # Either we merge and don't append quite yet
        # or append but set the last one and not append it 
        # in either case, we have an interval to append
        ans.append(prev)

        
        return ans

