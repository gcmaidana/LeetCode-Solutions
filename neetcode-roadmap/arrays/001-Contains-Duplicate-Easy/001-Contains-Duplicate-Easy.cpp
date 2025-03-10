// Problem link: https://leetcode.com/problems/contains-duplicate/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::unordered_set<int> mySet;

        for (int num : nums)
        {
            if (mySet.find(num) != mySet.end())
            {
                return true;
            }
            else
            {
                mySet.insert(num);
            }
        }

        return false;
    }
};
