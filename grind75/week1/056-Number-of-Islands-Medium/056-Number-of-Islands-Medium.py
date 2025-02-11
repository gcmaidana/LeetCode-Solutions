# Question link: https://leetcode.com/problems/number-of-islands/

# This BFS on a Matrix type problem is similar to both:
# 1. 01 Matrix
# 2. Rotting Oranges
# Refer to those problems for more practice
# This BFS matrix problems are a bit tricky at first, but they all follow a similar pattern and become
# fairly easy to solve, they just require a lot of code and careful thought to work through, but they're not
# overly complicated once you become familiar with the process of how to handle the BFS on the matrix

class Solution:

    def numIslands(self, grid: List[List[str]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        visited = set()
        islands = 0
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        q = deque()
        def bfs(r, c):
            visited.add((r,c))
            q.append((r, c))

            while q:
                row, col = q.popleft()
                for dr, dc in directions:
                    r = row + dr
                    c = col + dc
                    if (0 <= r < ROWS and 0 <= c < COLS and grid[r][c] == "1" and (r, c) not in visited):
                        q.append((r, c))
                        visited.add((r, c))



        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1" and (r, c) not in visited:
                    bfs(r, c)
                    islands += 1
        
        return islands

        
                    

        
