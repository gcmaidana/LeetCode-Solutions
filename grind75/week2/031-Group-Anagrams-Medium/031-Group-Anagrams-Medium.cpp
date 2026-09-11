// link: https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Output appears to be an array of arrays of strings.

        // Hashmap where:
        //
        // KEY   = frequency count of each letter
        // VALUE = list of words with that frequency count
        //
        // We use a string as the key because C++'s unordered_map
        // already knows how to hash strings.
        unordered_map<string, vector<string>> anagramMap;

        // Go through every string in the input.
        for (string s : strs) 
        {
            array<int, 26> count = {};

            // Go through every character in the current string.
            for (char c : s) 
                count[c - 'a']++;

            string key;

            // Convert the freq count array into a string basically
            // to use in our hashmap
            for (int num : count)
            {
                key += to_string(num);
                key += "#"; 
                // the reason we need the hashtag is because assume we have 
                // a = 1
                // b = 11
                // c = 2
                // if we dont separate the values and we have 1112, its ambigious and could represent
                // a = 11
                // b = 1
                // c = 2
            }

            anagramMap[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& pair : anagramMap)
            result.push_back(pair.second);
 

        return result;
    }
};
