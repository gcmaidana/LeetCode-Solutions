// link: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int water = 0;
        while(l != r) 
        {
            int smalCol = std::min(height[l], height[r]);
            water = std::max(water, (r - l) * smalCol);
            if(height[l] < height[r])
                l++;
            else
                r -= 1;
        }
        return water;
    }
};
