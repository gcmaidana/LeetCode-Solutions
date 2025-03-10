// Problem link: https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        std::unordered_map<string, vector<string>> sortMap;
        for(int i = 0; i < strs.size(); i++)
        {
            // current word we're on, sort it, if it exists in hashmap, append the unsorted word
            // to the values using the sorted word (key)
            // if it doesnt exist, create it

            string word = strs[i];
            string sortedKey = word;
            std::sort(sortedKey.begin(), sortedKey.end());
            if(sortMap.find(sortedKey) != sortMap.end())
            {
                sortMap[sortedKey].push_back(word);
            }
            else
            {
                sortMap[sortedKey] = {strs[i]};
            }
        }

        for(auto [key, value] : sortMap)
        {
            ans.push_back(value);
        }


        return ans;
        
    }
};
