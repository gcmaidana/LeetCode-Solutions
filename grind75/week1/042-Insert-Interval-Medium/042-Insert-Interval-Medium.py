# Question link: https://leetcode.com/problems/insert-interval/description/

# In place solution is not required for this problem, but I'll still include it as a possible solution


 
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        # edge case
        if not intervals:
            return [newInterval]
        
        start = 0
        end = 1
        res = []

        for i in range(len(intervals)):
            # new interval is to the right of this current interval
            if intervals[i][end] < newInterval[start]:
                res.append(intervals[i])

            # new interval is to the left of this current interval
            elif intervals[i][start] > newInterval[end]:
                res.append(newInterval)
                return res + intervals[i:]

            # there's an overlap
            else:
                newInterval[start] = min(intervals[i][start], newInterval[start])
                newInterval[end] = max(intervals[i][end], newInterval[end])

        # accounts for edges like this:
        # example 1: 
        # .---.
        #   .--new--.
        # example2:
        # .---.
        #       .---new---.
        res.append(newInterval)

        return res

                

# In place solution

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        start = i = 0
        end = 1
        while i < len(intervals):
            if newInterval[start] <= intervals[i][end]:
                if newInterval[end] < intervals[i][start]:
                    break
                newInterval[start] = min(newInterval[start], intervals[i][start])
                newInterval[end] = max(newInterval[1], intervals[i][end])
                intervals.pop(i)
            else:
                i += 1
        intervals.insert(i, newInterval)
        return intervals

        


        
