// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Grid is 9x9

        // Maps will use set since values cannot repeat
        // map => row : values
        // map => col : values
        // map => (r/3, c/3) : values, e.g. what values are in each sub grid
        unordered_map<int, unordered_set<char>> rowMap;
        unordered_map<int, unordered_set<char>> colMap;
        map<pair<int, int>, unordered_set<char>> subGridMap;

        for (int r = 0; r < 9; r++) 
        {
            for (int c = 0; c < 9; c++) 
            {
                if (board[r][c] == '.') 
                {
                  continue;
                }
                else 
                {
                    if (rowMap[r].count(board[r][c]) ||
                        colMap[c].count(board[r][c]) ||
                        subGridMap[{r / 3, c / 3}].count(board[r][c])) 
                      {
                      return false;
                      }
                    

                    rowMap[r].insert(board[r][c]);
                    colMap[c].insert(board[r][c]);
                    subGridMap[{r / 3, c / 3}].insert(board[r][c]);
                }
            } // end of inner for-loop
        } // end of outer for-loop

        return true;
    }
};
