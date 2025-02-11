# Question link: https://leetcode.com/problems/01-matrix/description/
# This question is a bit hard to understand at first, so here are some resources if I forget

# https://www.youtube.com/watch?v=HuZ3u2sRIPY
# Rotting orange problem is very similar in nature, probably easier to understand too
# https://github.com/gcmaidana/LeetCode-Solutions/blob/main/misc/994.%20Rotting%20Oranges%20(Medium)
# https://leetcode.com/problems/rotting-oranges/

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:

        ROWS = len(mat)
        COLS = len(mat[0])
        q = deque()
        directions = [(0,1), (0,-1), (1,0), (-1,0)]

        for r in range(ROWS):
            for c in range(COLS):
                if mat[r][c] == 0:
                    q.append((r,c))
                else:
                    mat[r][c] = float('-INF')
        
        while q:
            row, col = q.popleft()
            for dr, dc in directions:
                r = dr + row
                c = dc + col
                if 0 <= r < ROWS and 0 <= c < COLS and mat[r][c] == float('-INF'):
                    q.append((r,c))
                    mat[r][c] = mat[row][col] + 1
        
        return mat
    


        
