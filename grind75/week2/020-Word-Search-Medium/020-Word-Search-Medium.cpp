// link: https://leetcode.com/problems/word-search/description/

class Solution {
public:
    int ROWS, COLS;

    bool backtrack(vector<vector<char>>& board, string& word, int r, int c, int wordPtr) 
    {
        if (wordPtr == word.size()) {
            return true; // found the word
        }

        // out of bounds or mismatch
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[wordPtr]) 
        {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited

        bool ans = backtrack(board, word, r + 1, c, wordPtr + 1) ||
                   backtrack(board, word, r - 1, c, wordPtr + 1) ||
                   backtrack(board, word, r, c + 1, wordPtr + 1) ||
                   backtrack(board, word, r, c - 1, wordPtr + 1);

        board[r][c] = temp; // restore

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) 
        {
            for (int c = 0; c < COLS; c++) 
            {
                if (board[r][c] == word[0]) 
                {
                    if (backtrack(board, word, r, c, 0)) 
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
