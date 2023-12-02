Question link: https://leetcode.com/problems/diameter-of-binary-tree/
Video link(s): https://www.youtube.com/watch?v=bkxqA8Rfv04&t=456s


# Work bottom up instead of top down to reduce repeated work
# H = 1 + max(left, right)
# D = L + R 



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:

        # diameter = left sub tree + right sub tree
        max_diameter = [0] # mutable object (global variable), so works fine in dfs function

        def dfs(root):
            if not root:
                return 0
            
            left = dfs(root.left)
            right = dfs(root.right)
            
            max_diameter[0] = max(max_diameter[0], left + right)

            return 1 + max(left, right) 



        dfs(root)
        return max_diameter[0]

        
