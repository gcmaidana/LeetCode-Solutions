// https://leetcode.com/problems/gas-station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        // edge case: check if no solution exists, e.g. is our total gas available < cost
        // If there exists a solution, it is guaranteed to be unique.
        // If this were not the case with this problem, technically we would want to check:
        // total gas available < cost, since we could have gas available == cost, which produces multiple
        // solutions
        if (accumulate(gas.begin(), gas.end(), 0) 
            < accumulate(cost.begin(), cost.end(), 0)) 
        {
            return -1;
        }

        // constraint:
        // gas.length == cost.length == n, nice!
        // one unique solution

        int total = 0;
        int result_idx = 0;

        for (int i = 0; i < gas.size(); i++) 
        {
            total += (gas[i] - cost[i]);

            if (total < 0) 
            {
                total = 0;
                result_idx = i + 1; // if total is negative, we cannot be at i, res must be later
            }
        }

        return result_idx;
    }
};
