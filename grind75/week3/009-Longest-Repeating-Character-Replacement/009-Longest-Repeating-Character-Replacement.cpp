// problem link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::unordered_map<char, int> count;
        int res = 0, l = 0;

        for (int r = 0; r < s.size(); ++r) {
            count[s[r]]++;

            // Compute max frequency value explicitly (less optimized)
            int maxFreq = 0;
            for (const auto& pair : count) {
                maxFreq = std::max(maxFreq, pair.second);
            }

            while ((r - l + 1) - maxFreq > k) {
                count[s[l]]--;
                l++;
            }

            res = std::max(res, r - l + 1);
        }
        return res;
    }
};


// optimized

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::unordered_map<char, int> count;
        int res = 0, l = 0, maxFreq = 0;

        for (int r = 0; r < s.size(); ++r) {
            count[s[r]]++;
            maxFreq = std::max(maxFreq, count[s[r]]);

            while ((r - l + 1) - maxFreq > k) {
                count[s[l]]--;
                l++;
            }

            res = std::max(res, r - l + 1);
        }
        return res;
    }
};
