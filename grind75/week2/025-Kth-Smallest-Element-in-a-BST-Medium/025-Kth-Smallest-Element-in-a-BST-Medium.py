# link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Inorder traversal gives you the smallest nodes first, so add them to an array,
# when the array length gets to length k, we have our answer, ezpz
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        ans = []
        def inorder(root):

            # base case
            if root is None:
                return 

            inorder(root.left)

            # handle current root
            if len(ans) == k:
                return

            ans.append(root.val)

            inorder(root.right)
        
        inorder(root)
        return ans[-1]
        
