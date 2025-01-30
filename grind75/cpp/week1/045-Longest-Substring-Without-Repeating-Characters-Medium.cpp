// Problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxLength = 0;
        std::unordered_set<char> mySet;
        while (r < s.size())
        {
            // if s[r] not in set
            if(mySet.find(s[r]) == mySet.end())
            {
                mySet.insert(s[r]);
                r++;
                maxLength = std::max(maxLength, r - l);
            }
            else
            {
                mySet.erase(s[l]);
                l++;
            }
               
        }
        return maxLength;   
    }
};

// Or if too lazy to increment counters manually
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, maxLength = 0;
        std::unordered_set<char> mySet;
        for(int r = 0; r < s.size(); r++)
        {
           // Remove characters from the left until s[r] is not in the set
            while (mySet.find(s[r]) != mySet.end()) {
                mySet.erase(s[l]);
                l++;
            }
            // Add the current character to the set
            mySet.insert(s[r]);
            // Update the maximum length
            maxLength = std::max(maxLength, r - l + 1);
        }
        return maxLength;   
    }
};

