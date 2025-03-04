# https://leetcode.com/problems/rotting-oranges/description/
# This problem is similar to the problem "01 Matrix", and "Number of Islands" problems. Check those out if you want more practice on BFS matrix problems

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        q = deque()
        directions = [(0,1), (0,-1), (1,0), (-1,0)]
        minutes = fresh = 0

        # Count fresh oranges, if rotten then append to queue
        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 1:
                    fresh += 1
                elif grid[r][c] == 2:
                    q.append((r,c))
        
        # while something is in the queue and we have fresh oranges
        # left to check for
        while q and fresh > 0:
            # expand outwards from rotten oranges, and keep going for the new
            # rotten oranges in the while loop after we exit this for-loop or "minute"
            for i in range(len(q)):
                row, col = q.popleft()
                for dr, dc in directions:
                    r = row + dr
                    c = col + dc
                    if 0 <= r < ROWS and 0 <= c < COLS and grid[r][c] == 1:
                        grid[r][c] = 2 # this orange is now rotten
                        q.append((r,c)) # add rotten orange to q
                        fresh -= 1
            minutes += 1
        
        # isolated oranges can exist, so we can have fresh > 0
        return minutes if fresh == 0 else -1
        
        


        



        
