# Problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
            
        if root == p or root == q:
            return root

        
        # Search for LCA in the left and right subtrees
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        
        # If both left and right are non-null, this node is the LCA
        if left and right:
            return root
        
        # Otherwise, return either the left result or the right result
        return left if left else right

# T: O(N)
# S: O(1) if not counting recursive stack frames otherwise O(N)
