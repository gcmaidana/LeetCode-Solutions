// Problem link: https://leetcode.com/problems/number-of-islands/

class Solution {
public:

    int bfs(int r, int c, vector<vector<char>>& grid, set<pair<int, int>>& visited, vector<pair<int, int>>& directions) {
        queue<pair<int, int>> q;
        visited.insert({r, c});
        q.push({r, c});

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < grid.size() && 
                    nc >= 0 && nc < grid[0].size() && 
                    grid[nr][nc] == '1' && 
                    visited.find({nr, nc}) == visited.end()) 
                        {
                        q.push({nr, nc});
                        visited.insert({nr, nc});
                        }
            }
        }
        return 0;
    }


    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        set<pair<int, int>> visited;
        int islands = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == '1' && visited.find({r, c}) == visited.end()) {
                    bfs(r, c, grid, visited, directions);
                    islands++;
                }
            }
        }

        return islands;
        
    }
};

// More optimal, clean approach, no data structures
class Solution {
public:

    int bfs(int r, int c, vector<vector<char>>& grid) 
    {
        if(r >= 0 && r < grid.size() &&
           c >= 0 && c < grid[0].size() &&
           grid[r][c] == '1')
        {
            grid[r][c] = '0';
            bfs(r + 1, c, grid);
            bfs(r - 1, c, grid);
            bfs(r, c + 1, grid);
            bfs(r, c - 1, grid);
        }
        return 0;
    }


    int numIslands(vector<vector<char>>& grid) {

        int ROWS = grid.size();
        int COLS = grid[0].size();
        int islands = 0;
    
        for (int r = 0; r < ROWS; ++r) 
        {
            for (int c = 0; c < COLS; ++c) 
            {
                if (grid[r][c] == '1') 
                {
                    bfs(r, c, grid);
                    islands++;
                }
            }
        }

        return islands;
        
    }
};
