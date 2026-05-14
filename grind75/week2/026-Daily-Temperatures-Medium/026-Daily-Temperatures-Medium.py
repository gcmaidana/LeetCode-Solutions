# link: https://leetcode.com/problems/daily-temperatures/
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        my_stack = []
        ans = [0] * len(temperatures)

        for i in range(len(temperatures)):

            while my_stack and temperatures[i] > temperatures[my_stack[-1]]:
                idx = my_stack.pop()
                ans[idx] = i - idx
            my_stack.append(i)
            
        return ans
        
