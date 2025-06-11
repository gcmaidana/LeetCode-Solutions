// problem link: https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0, bottom = ROWS - 1;
        int left = 0, right = COLS - 1;

        while (top <= bottom && left <= right)
        {
            // move left to right
            for(int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // move top to bottom
            for(int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            // right to left
            if(top <= bottom)
            {
                for(int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // bottom to top
            if(left <= right)
            {
                for(int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++; 
            }
        }
        
        return ans;
    }
};
