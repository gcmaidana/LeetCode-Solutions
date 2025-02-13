# Question link: https://leetcode.com/problems/min-stack/
# This one can be a little tricky, I'm not gonna explain it through comments, just watch this video, it's more concise
# yt: https://www.youtube.com/watch?v=qkLl7nAwDPo

class MinStack:

    def __init__(self):
        self.stack = []
        self.minStack = []
        

    def push(self, val: int) -> None:
        self.stack.append(val)
        if not self.minStack:
            self.minStack.append(val)
        else:
            val = min(val, self.minStack[-1])
            self.minStack.append(val)
        

    def pop(self) -> None:
        self.stack.pop()
        self.minStack.pop()
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
       return self.minStack[-1] 



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
