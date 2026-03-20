// link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
class Solution {
private:
    void backtrack(int index, string currentString, 
        string& digits, unordered_map<char, string>& digits_map, vector<string>&ans)
    {
        if (currentString.size() == digits.size())
        {
            ans.push_back(currentString);
            return;
        } 

        string letters = digits_map[digits[index]];
        for(char letter : letters)
        {
            backtrack(index + 1, currentString + letter,
                      digits, digits_map, ans);
        }
    }


public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char, string> digits_map = 
        {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;


        backtrack(0, "", digits, digits_map, ans);
        return ans;

    }
};
