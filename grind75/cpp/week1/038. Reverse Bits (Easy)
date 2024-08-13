// Problem link: https://leetcode.com/problems/reverse-bits/description/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            ans = ans << 1;
            int bit = n & 1;
            ans = ans | bit;
            n = n >> 1;
        }

        return ans;
    }
};
