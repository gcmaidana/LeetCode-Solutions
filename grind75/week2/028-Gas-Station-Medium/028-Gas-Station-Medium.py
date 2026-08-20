class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:

        # edge case: check if no solution exists, e.g. is our total gas available < cost
        # If there exists a solution, it is guaranteed to be unique.
        # If this were not the case with this problem, technically we would want to check:
        # total gas available < cost, since we could have gas avaiable == cost, which produces multiple
        # solutions
        if sum(gas) < sum(cost):
            return -1

        # constraint: 
        # gas.length == cost.length == n, nice!
        # one unique solution

        total  = 0
        result_idx = 0
        for i in range(len(gas)):
            total += (gas[i] - cost[i])
            if total < 0:
                total = 0
                result_idx = i + 1 # if total is negative, we cannot be at i, res must be later

        
        return result_idx
