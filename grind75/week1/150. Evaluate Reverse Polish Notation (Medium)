# Question link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for t in tokens:
            if t == "+" or t == "-" or t == "*" or t == "/":
                s1 = stack.pop()
                s2 = stack.pop()
                ans = None
                if t == "+":
                    ans = s1 + s2
                    stack.append(ans)
                
                elif t == "-":
                    ans = s2 - s1
                    stack.append(ans)
                
                elif t == "*":
                    ans = s1 * s2
                    stack.append(ans)


                else: 
                    # (int)(s1/s2) truncates toward 0, whereas s1 // s2 truncates toward negative inf
                    # for example,
                    # 6 / -132 should give us 0
                    # if we use 6 // -132, we get -1, so we get incorrect answer for example 3
                    ans = (int) (s2 / s1) 
                    stack.append(ans)
            else:
                stack.append((int)(t))

        return stack.pop() # final element should be the answer
        
