# Question link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/
# I don't think this problem is too difficult conceptually speaking, just use a BFS and add every node from a particular level to its own list, and return the list of the lists

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if not root:
            return result
        
        queue = collections.deque()
        queue.append(root)

        while queue:
            size = len(queue)
            level = []

            for i in range(size):
                node = queue.popleft()

                if node:
                    level.append(node.val)

                    if node.left:
                        queue.append(node.left)
                    
                    if node.right:
                        queue.append(node.right)

            result.append(level)

        return result        
