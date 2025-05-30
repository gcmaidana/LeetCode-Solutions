// Problem link: https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Strip leading whitespace
        while (i < n && s[i] == ' ') 
        {
            i++;
        }

        // Handle sign
        int sign = 1;
        if (i < n && s[i] == '-') 
        {
            sign = -1;
            i++;
        } 
        else if (i < n && s[i] == '+') 
        {
            i++;
        }

        // Handle digits
        long result = 0; // use long to detect overflow before clamping
        while (i < n && isdigit(s[i])) 
        {
            result = result * 10 + (s[i] - '0');

            // Clamp if overflow detected
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * result;
    }
};
