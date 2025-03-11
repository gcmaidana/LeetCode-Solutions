// Problem link: https://leetcode.com/problems/permutations/

// Least optimal solution but helps you understand what to do
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        if(nums.size() == 1)
        {
            return {nums};
        }

        

        std::vector<std::vector<int>> ans;
        std::vector<int> permArr;

        std::function<void()> bt = [&]()
        {
            if(permArr.size() == nums.size())
            {
                ans.push_back(permArr);
                return;
            }

            for(int x : nums)
            {
                // is x in permutation array? if not, add it!
                if(std::find(permArr.begin(), permArr.end(), x) == permArr.end())
                {
                    permArr.push_back(x);
                    bt();
                    permArr.pop_back();
                }
            }
        };

        

        bt();
        return ans;
    }
};


// Slightly more optimal uses a set for faster lookup
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
{
        // Base case: If nums has only one element, return it as a single permutation
        if (nums.size() == 1) 
        {
            return {nums}; // Return a vector of vectors containing the single element
        }

        vector<vector<int>> ans; // To store all permutations
        unordered_set<int> used; // To track used elements in the current permutation

        // Helper function for backtracking
        function<void(vector<int>&)> bt = [&](vector<int>& permArr) 
    {
            // If the current permutation array has the same size as nums, add it to ans
            if (permArr.size() == nums.size()) 
            {
                ans.push_back(permArr);
                return;
            }

            for (int x : nums) {
                if (used.find(x) == used.end()) 
                { // If x is not yet used
                    used.insert(x); // Mark x as used
                    permArr.push_back(x); // Add x to the current permutation
                    bt(permArr); // Recurse with the updated permutation
                    permArr.pop_back(); // Backtrack: remove the last element
                    used.erase(x); // Unmark x as used
                }
            }
        };

        vector<int> permArr; // Temporary array to build permutations
        bt(permArr); // Start backtracking with an empty array

        return ans; // Return all permutations
    }
};
