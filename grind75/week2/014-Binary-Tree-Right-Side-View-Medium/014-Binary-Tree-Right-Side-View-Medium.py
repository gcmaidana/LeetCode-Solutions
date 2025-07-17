# problem link: https://leetcode.com/problems/binary-tree-right-side-view/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        # base case
        if not root:
            return []

        queue = collections.deque([root])
        res = []
        while queue:
            level_len = len(queue)

            for i in range(level_len):
                node = queue.popleft()
                
                if i == level_len - 1: #right mode node
                    res.append(node.val)
                
                if node.left:
                    queue.append(node.left)
                
                if node.right:
                    queue.append(node.right)
                
        return res
        
        
