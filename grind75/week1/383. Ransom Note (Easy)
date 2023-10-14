# Question link: https://leetcode.com/problems/ransom-note/
# Notes: Ransom note string has to be constructed using the letters from magazine string
#
# We can count the frequency of letters in magazine string and store it in a hash map
#
# We then iterate over ransom note string characters, and if a character does not exist in magazine
# or if there are no more unique characters left, we return false, otherwise we return true
#
# By unique characters, I mean that ransom note "aa" has to be made up of a magazine string "aab", it
# cannot be made up of a magazine string like "ab"
#
# The way we track unique characters if by decrementing the frequency of a particular letter in magazine hash map
# once we encounter it as we iterate over the ransom note string characters

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        hashmapMag = {}

        for char in magazine:
            if char in hashmapMag:
                hashmapMag[char] += 1
            else:
                hashmapMag[char] = 1

        for char in ransomNote:
            if char not in hashmapMag or hashmapMag[char] < 1:
                return False
            else:
                hashmapMag[char] -= 1        
        return True
        
