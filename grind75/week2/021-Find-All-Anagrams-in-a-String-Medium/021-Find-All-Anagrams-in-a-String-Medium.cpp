// link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // cannot make anagrams if len of p is greater than len of s
        if (s.length() < p.length()) {
            return {};
        }

        unordered_map<char, int> p_map;
        unordered_map<char, int> s_map;
        vector<int> ans;

        // build p_map (equivalent to Counter)
        for (char c : p) {
            p_map[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            // add current char to s_map
            s_map[s[i]]++;

            // remove char that slides out of window
            if (i >= p.length()) {
                char leftChar = s[i - p.length()];
                if (s_map[leftChar] == 1) {
                    s_map.erase(leftChar);
                } else {
                    s_map[leftChar]--;
                }
            }

            // compare maps
            if (p_map == s_map) {
                ans.push_back(i - p.length() + 1);
            }
        }

        return ans;
    }
};
