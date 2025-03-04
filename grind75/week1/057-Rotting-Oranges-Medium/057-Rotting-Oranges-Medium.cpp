// Problem link: https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;

        // Count fresh oranges, and also append rotten ones to q
        for (int r = 0; r < ROWS; r++) 
        {
            for (int c = 0; c < COLS; c++) 
            {
                if (grid[r][c] == 1) 
                {
                    fresh++;
                } 
                else if (grid[r][c] == 2) 
                {
                    q.push({r, c});
                }
            }
        } 

        // While something is in the q and we have fresh oranges, keep rotting
        while(!q.empty() && fresh > 0)
        {
            // expand outwards from rotten ranges and keep going for the new rotten ones
            // in the while loop after we exit this loop or "minute" (assuming fresh>0 too) 
            int size = q.size();  // Store the current size of the queue
            for(int i = 0; i < size; i++)  // Use the stored size
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (auto [dr, dc] : directions)
                {
                    int r = row + dr;
                    int c = col + dc;
                    if(0 <= r && r < ROWS &&
                       0 <= c && c < COLS &&
                       grid[r][c] == 1)
                       {
                        grid[r][c] = 2; // this orange is now rotten
                        fresh -= 1; // one less fresh orange :(
                        q.push({r,c}); // add rotten orange to q
                       }
                } // inner for

            } // outer for
            minutes += 1;
        } // end while

        // isolated oranges can exist, so we can have fresh > 0
        return fresh == 0 ? minutes : -1;
        
    }
};
