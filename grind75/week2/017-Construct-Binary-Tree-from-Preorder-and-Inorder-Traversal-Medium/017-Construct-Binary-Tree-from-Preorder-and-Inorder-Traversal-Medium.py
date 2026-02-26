# link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Notes: So when you find the root in the preorder list, where ever that root is in the inorder list, everything to 
# left of the root in that inorder list will be in the left subtree, everything to the right of that value will be 
# in the right subtree for the output

# 1.) Use preorder to find the root
# 2.) Find the root in inorder. Everything to the left of that value in the inorder list will be in the 
#     left subtree for the output, everything to the right of that value in the inorder list will be in the right subtree
#     for the output
# 3.) Now that we found the root in the inorder list. Recursive call the function on everything to the left of the
#     root in inorder (left subtree of the output) to find what the root should be. And also recursively call 
#     the function on everything to the right of the root in inorder list (right subtree) to find the root). 
#     This will build your output.find on the left subtree to find what the root should be, and recursively 
#     call the function on the right subtree to find what the root should be for that


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

      

        # in order to not have to go through inorder to find the root every time, let's store the indexes
        # in a hashmap for fast lookup, otherwise our solution would be O(N^2)
        mapping = {}
        for i in range(len(inorder)):
            mapping[inorder[i]] = i

        current = 0
        def parse_inorder(left, right):
            # base case
            if left > right:
                return None

            nonlocal current # specify this is defined outside of function
            root = preorder[current]
            current += 1

            middle = mapping[root]

            node = TreeNode(root)
            node.left = parse_inorder(left, middle - 1)
            node.right = parse_inorder(middle + 1, right)

            return node
        
        return parse_inorder(0, len(inorder) - 1)
    
