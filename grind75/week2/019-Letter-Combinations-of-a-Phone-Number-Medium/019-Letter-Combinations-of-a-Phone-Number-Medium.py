# link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # map numbers to letters
        digits_map = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        ans = []
        

        def backtrack(index, curr_str):
            # base case
            if len(curr_str) == len(digits):
                ans.append(curr_str)
                return

            letters = digits_map[digits[index]]
            for letter in letters:
                
                backtrack(index + 1, curr_str + letter)
        
        backtrack(0, "")
        return ans
