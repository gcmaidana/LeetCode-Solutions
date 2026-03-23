// link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // cannot make anagrams if len of p is greater than the len of s
        if (s.length() < p.length())
            return {};
        
        unordered_map<char, int> pMap;
        unordered_map<char, int> sMap;
        vector<int> ans;

        for (char c : p)
            pMap[c]++;
        
        for(int i = 0; i < s.length(); i++)
        {
            sMap[s[i]]++;

            if(i >= p.length())
            {
                char leftChar = s[i - p.length()];
                if(sMap[leftChar] == 1)
                    sMap.erase(leftChar);
                else
                    sMap[leftChar]--;
            }

            if(pMap == sMap)
                ans.push_back(i - p.length() + 1);
                 
        }


        return ans;
    }
};
