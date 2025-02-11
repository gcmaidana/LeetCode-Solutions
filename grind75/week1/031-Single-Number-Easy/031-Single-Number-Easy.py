# Question link: https://leetcode.com/problems/single-number/
# a num xor with itself is 0, so we will be left with the single number left in the list
# I'm leaving this explanation below in case me or someone else needs to it in the future. It's better
# to keep this here rather than have to scramble elsewhere to get a concise answer on the difference.
# This explanation below also helps visualize the problem

The OR and XOR are both binary operations, but they work a bit differently:

OR (Inclusive OR): This operation returns true if at least one of the operands (inputs) is true. In other words, if either or both of the inputs are true, the output is true. If both inputs are false, the output is false
Here’s the truth table for OR:

Table

Input A	Input B	Output (A OR B)
0	0	0
0	1	1
1	0	1
1	1	1


XOR (Exclusive OR): This operation returns true if exactly one of the operands is true. If both inputs are true or both inputs are false, the output is false

Here’s the truth table for XOR:

Table

Input A	Input B	Output (A XOR B)
0	0	0
0	1	1
1	0	1
1	1	0
So, the key difference between OR and XOR is that OR returns true if either or both inputs are true, while XOR returns true only if exactly one of the inputs is true

class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        if len(nums) == 1:
            return nums[0]
        
        res = nums[0]
        for num in nums[1:]:
            res = res ^ num
        return res

# Alternate (but same solution)
class Solution:
    def singleNumber(self, nums: List[int]) -> int:

        x = 0 
        for i in nums:
            x ^= i
        return x

        
        
