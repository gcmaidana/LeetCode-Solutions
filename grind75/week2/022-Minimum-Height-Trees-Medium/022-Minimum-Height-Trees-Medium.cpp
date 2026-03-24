// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // edge case
        if (n == 1) {
            return {0};
        }
            
        // adj list
        vector<vector<int>> adj_list(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            adj_list[a].push_back(b); // add edge a->b
            adj_list[b].push_back(a); // add edge b->a
            degree[a] += 1;
            degree[b] += 1;
        }
        
        queue<int> leaves;
        
        // Find the leaves and append to q
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        int remaining_nodes = n;

        while (remaining_nodes > 2) {
            // We will handle current layer of leaves
            // So decrement remaining_nodes by leaf_count
            int leaf_count = leaves.size();
            remaining_nodes -= leaf_count;

            // Peel off the outer layer of leafs 
            // Update the degree of the neighbor of the leaves since the leaf is removed,
            // if degree of the neighbor is == 1, it's also a leaf, so append it to the q
            for (int i = 0; i < leaf_count; i++) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : adj_list[leaf]) {
                    degree[neighbor] -= 1;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};
