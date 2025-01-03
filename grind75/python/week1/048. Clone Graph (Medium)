# Question link: https://leetcode.com/problems/clone-graph/description/
# YT: https://www.youtube.com/watch?v=mQeF6bN8hMk

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:

        if not node:
            return None
        
        # old node => new cloned node
        clone = {}

        def dfs(node):
            if node in clone:
                return clone[node]
            
            copy = Node(node.val)
            clone[node] = copy

            # Handle the neighbors by recursively cloning them
            for neighbor in node.neighbors:
                copy.neighbors.append(dfs(neighbor))
            
            return copy


        return dfs(node)
        
