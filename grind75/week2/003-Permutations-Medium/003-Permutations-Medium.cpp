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
