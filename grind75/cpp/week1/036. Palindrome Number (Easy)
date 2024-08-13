// Problem link: 

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {return false;}

        // long works, but if our constraints were stricer, we could use long long as well
        long dummyX = x;
        long reversedNum = 0;
        while(dummyX)
        {
            reversedNum = reversedNum * 10 + dummyX % 10;
            dummyX = dummyX / 10;
        }

        return x == reversedNum;
        
    }
};
