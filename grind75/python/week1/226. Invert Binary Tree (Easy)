# Question link: https://leetcode.com/problems/invert-binary-tree/

# Notes: I had no idea where to start with this one, but once I looked up the
# solution I understood it. Inverting the binary tree involves swapping the left and right child nodes of each node in the tree. 
# We start from the root node, and swap the left and right child nodes, and we apply this same operation recursively to the each child node.
# We do this for each child node (subtree) until we reach our base case which is where there are no child nodes for a particular given node.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

            # basically take the tree to left and right of root
            # node and swap, then we can invert the sub tress
        tmp = root.left
        root.left = root.right
        root.right = tmp
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root

# 2nd solution post order traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        if not root:
            return

        left = self.invertTree(root.left)
        right = self.invertTree(root.right)

        root.right = left
        root.left = right

        return root
        


# 3rd solution pre order traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        # post order traversal

        if not root:
            return

        root.left, root.right = root.right, root.left # as long as this is on one line, the right wont get overwritten by the left assignment in python
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root

        
