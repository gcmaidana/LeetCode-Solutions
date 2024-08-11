// Problem link: https://leetcode.com/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> hashmapMag;

        for(int i = 0; i < magazine.size(); i++)
        {
            if (hashmapMag.count(magazine[i]))
            {
                hashmapMag[magazine[i]] += 1;
            }
            else
            {
                hashmapMag[magazine[i]] = 1;
            }
        }

        for(int i = 0; i < ransomNote.size(); i++)
        {
            if (!hashmapMag.count(ransomNote[i]) || hashmapMag[ransomNote[i]] == 0)
            {
                return false;
            }
            else
            {
                hashmapMag[ransomNote[i]] -= 1;
            }
        }

        return true;
    }
};
