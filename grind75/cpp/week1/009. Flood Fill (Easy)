// Problem link: https://leetcode.com/problems/flood-fill/

class Solution {
public:

    void fill(vector<vector<int>>& image, int sr, int sc, int startPix, int col)
    {
        if (0 <= sr && sr < image.size() && 0 <= sc && sc < image[0].size() && image[sr][sc] == startPix && image[sr][sc] != col)
        {
            image[sr][sc] = col;
            fill(image, sr - 1, sc, startPix, col);
            fill(image, sr + 1, sc, startPix, col);
            fill(image, sr, sc - 1, startPix, col);
            fill(image, sr, sc + 1, startPix, col);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startingPixel = image[sr][sc];
        fill(image, sr, sc, startingPixel, color);
        return image;
        
    }
};
