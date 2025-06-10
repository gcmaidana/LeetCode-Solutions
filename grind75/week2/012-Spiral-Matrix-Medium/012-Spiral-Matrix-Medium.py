# problem link: https://leetcode.com/problems/spiral-matrix/
# good video for this problem: https://www.youtube.com/watch?v=3Zv-s9UUrFM
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:

        # Think about how our spiral will work:
        # Go right, go down, go left, go up
        # We start at top left, so how would we do this?
        # Go from left -> right
        # Then right -> bottom
        # Bottom -> left
        # left -> top
        # Imagine we have imaginary 4 walls which are the boundaries by which
        # our spiral should work within as we progress, that's the trick to this problem

        ROWS = len(matrix)
        COLS = len(matrix[0])
        ans = []

        top = 0
        bottom = ROWS - 1
        left = 0
        right = COLS - 1

        while top <= bottom and left <= right:

            # move from left to right
            for i in range(left, right+1):
                ans.append(matrix[top][i])
            top += 1

            # move from top to bottom
            for i in range(top, bottom+1):
                ans.append(matrix[i][right])
            right -= 1 

            # move from right to left
            if top <= bottom:   
                for i in range(right, left - 1, -1):
                    ans.append(matrix[bottom][i])
                bottom -= 1 

            # move from bottom to top
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    ans.append(matrix[i][left])
                left += 1 

        return ans

        
