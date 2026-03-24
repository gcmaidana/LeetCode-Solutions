# https://leetcode.com/problems/minimum-height-trees/

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        # edge case
        if n == 1:
            return [0]
            
        # adj list
        adj_list = defaultdict(list)
        degree = [0] * n
        for a, b in edges:
            adj_list[a].append(b) # add edge a->b
            adj_list[b].append(a) # add edge b->a
            degree[a] += 1 
            degree[b] += 1
        
        leaves = deque()
        
        # Find the leaves and append to q
        for i in range(n):
            if degree[i] == 1:
                leaves.append(i)
        remaining_nodes = n

        
        while remaining_nodes > 2:
            # We will handle current layer of leaves
            # So decrement remaining_nodes by leaf_count
            leaf_count = len(leaves)
            remaining_nodes -= leaf_count

            # Peel off the outer layer of leafs 
            # Update the degree of the neighbor of the leaves since the leaf is removed,
            # if degree of the neighbor is == 1, it's also a leaf, so append it to the q
            for _ in range(leaf_count):
                leaf = leaves.popleft()
                for neighbor in adj_list[leaf]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        leaves.append(neighbor)
                        
        return list(leaves)
        


        
