# problem link: https://leetcode.com/problems/merge-intervals/description/

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:

        # output is a list of list
        # what to do if overlap point on point, e.g. 2, and 2

        # fucking disgusting problem can have unsorted start times
        # like [[1,3], [0,5]]
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

        '''
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
    .___.
      ._______.
                  .____.
                                      ._________.
        '''
        

      
