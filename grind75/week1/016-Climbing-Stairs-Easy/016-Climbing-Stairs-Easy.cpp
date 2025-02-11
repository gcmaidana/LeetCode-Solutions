// Problem link: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {

        if(n <= 2) { return n; }

        int n_minus_one = 2;
        int n_minus_two = 1;
        int currentN = 0;
        
        for(int i = 3; i <= n; i++)
        {
            currentN = n_minus_one + n_minus_two;
            n_minus_two = n_minus_one;
            n_minus_one = currentN;
        }
        return currentN;
    }
};
