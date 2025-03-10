# Question link: https://leetcode.com/problems/valid-anagram/

# Notes: I used a hashmap to count the frequency of the letters in string s then decrement that hashmap count using t.
# Return false if letter doesnt exist in hashmap when doing the t loop or if count == 0 since we have more in t than in s at that point

# "What if the inputs contain Unicode characters? How would you adapt your solution to such a case?"
# Hashmap is best to address this issue unlike an array of 26 characters
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hashmapLetters = {}
        if len(s) != len(t):
            return False



        for char in s:
            if char not in hashmapLetters:
                hashmapLetters[char] = 1
            else:
                hashmapLetters[char] += 1
        
        for char in t:
            if char not in hashmapLetters or hashmapLetters[char] == 0:
                return False
            else:
                hashmapLetters[char] -= 1

        return True




Solution 2, probably not an acceptable answer in interview to be honest

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
