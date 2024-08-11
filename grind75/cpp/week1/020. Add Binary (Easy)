// Problem link: https://leetcode.com/problems/add-binary/description/

class Solution {
public:
    string addBinary(string a, string b) {
        int pointerA = a.size() - 1;
        int pointerB = b.size() - 1;
        int carry = 0;
        string ans;

        while(pointerA >= 0 || pointerB >= 0)
        {
            int digitA = pointerA >= 0 ? a[pointerA] - '0' : 0;
            int digitB = pointerB >= 0 ? b[pointerB] - '0' : 0;
            int sumDigit = digitA + digitB + carry;
            ans += to_string(sumDigit % 2);
            carry = sumDigit / 2;
            pointerA -= 1;
            pointerB -= 1;
        }
        
        if (carry > 0)
        {
            ans += "1";
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
