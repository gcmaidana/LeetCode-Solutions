# Question link: https://leetcode.com/problems/validate-binary-search-tree/description/
# Think of this problem in terms of the lower and upper bound that a node must be within


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def validate(node, minimum, maximum):
            if node is None:
                return True
            
            if node.val <= minimum or node.val >= maximum:
                return False

            return (
                validate(node.left, minimum, node.val) and
                validate(node.right, node.val, maximum)
            )
        

        return validate(root, float('-inf'), float('inf'))

        
