// Problem link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min-heap to store the distance and corresponding points
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<int>> res;

        // Calculate squared distance and store in the heap
        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int z = (x * x) + (y * y);
            minHeap.push({z, {x, y}});
        }

        // Extract the k closest points
        while (k-- > 0 && !minHeap.empty()) {
            auto [z, point] = minHeap.top();
            minHeap.pop();
            res.push_back({point.first, point.second});
        }

        return res;
    }
};

