# link: https://leetcode.com/problems/word-search/description/

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        wordPtr = 0
        ROWS = len(board)
        COLS = len(board[0])
        def backtrack(r, c, wordPtr):
            if wordPtr == len(word):
                return True #found the word

            # if we are out of position or letter doesn't match what we expect
            if (r >= ROWS or c >= COLS or 
                r < 0 or c < 0 or 
                board[r][c] != word[wordPtr]):
                    return False

            tmp = board[r][c]
            board[r][c] = "#" # mark it seen, can alternatively use a set rather than modify the input
            ans = (backtrack(r + 1, c, wordPtr + 1) or
            backtrack(r - 1, c, wordPtr + 1) or
            backtrack(r, c + 1, wordPtr + 1) or
            backtrack(r, c - 1, wordPtr + 1))
            board[r][c] = tmp

            return ans
        
        for r in range(ROWS):
            for c in range(COLS):
                if board[r][c] == word[0]: # begin word search!
                    if backtrack(r, c, 0):
                        return True # word found!
        
        return False # word not found!
                

        
