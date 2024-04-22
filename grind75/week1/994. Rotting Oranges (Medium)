# https://leetcode.com/problems/rotting-oranges/description/
# This problem is similar to the problem "01 Matrix", and "Number of Islands" problems. Check those out if you want more practice on BFS matrix problems

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = deque()
       
       # time is how much time has passed for our output
       # fresh is how many fresh oranges we will have initially, so we know if we accounted for all oranges at the end, 
       # leave this 0 for now
        time, fresh = 0, 0 
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        ROWS = len(grid)
        COLS = len(grid[0])
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    fresh += 1
                elif grid[r][c] == 2:
                    queue.append((r, c))
        
        while queue and fresh > 0:

            for i in range(len(queue)):

                r, c = queue.popleft()
                
                # now we go through the adjacent spots to the rotten orange
                # dr = difference in row
                # dc = difference in col
                for dr, dc in directions:
                    row, col = dr + r, dc + c

                    # now we check to make sure row and col are in bounds, and that the coordinate leads to a non-rotten orange
                    # since we need to go from fresh->rotten for any adjacent oranges to a rotten one
                    if row < ROWS and row >= 0 and col < COLS and col >= 0 and grid[row][col] == 1:
                        grid[row][col] = 2 # turn the fresh orange to rotten!
                        
                        queue.append((row, col))
                        fresh -= 1
            time += 1
        return time if fresh == 0 else -1
