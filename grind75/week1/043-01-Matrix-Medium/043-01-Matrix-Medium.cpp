// Problem link: https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int ROWS = mat.size();
        int COLS = mat[0].size();
        std::queue<std::pair<int, int>> q;
        vector<vector<int>> directions = { {0,1}, {0, -1}, {1, 0}, {-1, 0} };


        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(mat[r][c] == 0)
                {
                    q.push({r,c});
                }
                else
                {
                    mat[r][c] = -1;
                }
            }
        }

        while(!q.empty())
        {
            std::pair<int, int> front = q.front();
            int row = front.first;
            int col = front.second;
            q.pop();

            // check each direction and do something...
            for(const auto& direction : directions)
            {
                int dr = direction[0];
                int dc = direction[1];
                int r = row + dr;
                int c = col + dc;
                if(0 <= r && r < ROWS && 0 <= c && c < COLS && mat[r][c] == -1)
                {
                    q.push({r, c});
                    mat[r][c] = mat[row][col] + 1;
                }
            }
        }

        return mat;
        
    }
};
