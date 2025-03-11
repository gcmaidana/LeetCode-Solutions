// Problem link: https://leetcode.com/problems/permutations/

// Least optimal solution but helps you understand what to do
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> perm_arr;

        // Backtracking function
        std::function<void()> bt = [&]() {
            if (perm_arr.size() == nums.size()) {
                ans.push_back(perm_arr);
                return;
            }

            for (int x : nums) {
                // Check if x is already in perm_arr
                if (std::find(perm_arr.begin(), perm_arr.end(), x) == perm_arr.end()) {
                    perm_arr.push_back(x);
                    bt();  // Recurse
                    perm_arr.pop_back();  // Backtrack
                }
            }
        };

        bt();  // Start the backtracking process
        return ans;
    }
};
