// link: https://leetcode.com/problems/longest-palindromic-substring/

// You can technically do this in O(N) using Manacher's Algorithm but I don't see a point in learning obscure algorithms
// You will likely forget and mess up in an interview, using the O(N^2) approach of expanding outwards is better
// than the brute force O(N^3). Learn it if yo want, in my opinion, I don't see value in learning the obscure solutions but it does exist so I want to note that.

// To check if a string is a palindrome, we can:
// 1. start from the outside and compare the two characters OR
// 2. start in the middle and expand outwards and do the comparison that way

// Which is better? Option 2. This way we can do a linear scan through the original string and do the comparison at each character and expand outwards. This will be O(N^2) but the brute force is significantly more inefficient so this is best.
// For ex: for 'babdf', we start at 'b' and check to the left and right, of course there is nothing to the left so b itself is the longest palindrome so far. We move onto the character 'a', we expand outwards and we see 'bab' is 
// the longest palindrome so far
// We keep doing this as we linearly scan through the string and we will find the longest palindrome. That being said, we have to handle the edge case of where we have an even length of characters for a palindrome like 'abba', 
// the way to handle this is set the pointers next to each other not at the same starting position

class Solution {
public:
    string longestPalindrome(string s) {
        int longest_len = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) 
        {
            // odd length palindrome
            int l = i, r = i; // pointers at center
            while (l >= 0 && r < s.size() && s[l] == s[r]) 
            {
                if (r - l + 1 > longest_len) 
                {
                    start = l;
                    longest_len = r - l + 1;
                }
                l--;
                r++;
            }

            // even length palindrome
            l = i;
            r = i + 1; // pointers next to each other
            while (l >= 0 && r < s.size() && s[l] == s[r]) 
            {
                if (r - l + 1 > longest_len) 
                {
                    start = l;
                    longest_len = r - l + 1;
                }
                l--;
                r++;
            }
        }

        // substring creates a copy, we only do it once here for efficiency
        return s.substr(start, longest_len);
    }
};


// Same as above but refactored into function
class Solution {
public:
    int longest_len = 0;
    int start = 0;

    // helper function to expand around center
    void expand(const string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) 
        {
            if (r - l + 1 > longest_len) 
            {
                start = l;
                longest_len = r - l + 1;
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) 
    {
        for (int i = 0; i < s.size(); i++) 
        {
            // odd length palindrome
            expand(s, i, i);
            
            // even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, longest_len);
    }
};
