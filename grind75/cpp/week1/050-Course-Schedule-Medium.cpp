// Problem link: https://leetcode.com/problems/course-schedule/description/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Edge case
        if (prerequisites.empty()) {
            return true;
        }

        unordered_set<int> visited;
        unordered_set<int> processed;
        unordered_map<int, vector<int>> courseGraph;

        // Build adjacency list
        for (const auto& prereq : prerequisites) {
            courseGraph[prereq[0]].push_back(prereq[1]);
        }

        function<bool(int)> dfs = [&](int course) {
            // Check if the course is already visited (cycle detected)
            if (visited.find(course) != visited.end()) {
                return false;
            }

            // Check if the course is already processed (no need to revisit)
            if (processed.find(course) != processed.end()) {
                return true;
            }

            visited.insert(course);
            for (int prereq : courseGraph[course]) {
                if (!dfs(prereq)) {
                    return false;
                }
            }

            visited.erase(course);
            processed.insert(course);

            return true;
        };

        for (int course = 0; course < numCourses; ++course) {
            if (!dfs(course)) {
                return false;
            }
        }

        return true;
        
    }
};
