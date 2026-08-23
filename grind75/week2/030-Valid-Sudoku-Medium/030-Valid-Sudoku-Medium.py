# https://leetcode.com/problems/valid-sudoku

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Grid is 9x9

        # Maps will use set since values cannot repeat
        # map => row : values
        # map => col : values
        # map => (r/3, c/3) : values, e.g what values are in each sub grid
        rowMap = defaultdict(set)
        colMap = defaultdict(set)
        subGridMap = defaultdict(set)
        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                else:
                    if (board[r][c] in rowMap[r] or
                       board[r][c] in colMap[c] or
                       board[r][c] in subGridMap[(r//3, c//3)]):
                        return False
                    rowMap[r].add(board[r][c])
                    colMap[c].add(board[r][c])
                    subGridMap[(r//3, c//3)].add(board[r][c])
        return True
                    

                    
