// https://leetcode.com/problems/task-scheduler/

// Less efficient Max Heap approach
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
    
        unordered_map<char, int> count;
        for (char t : tasks) 
            count[t]++;

        // max heap (priority queue)
        priority_queue<int> maxHeap;
        for (auto& [task, cnt] : count) 
        {
            maxHeap.push(cnt);
        }

        int time = 0;

        // queue: {remaining_count, available_time}
        queue<pair<int, int>> cooldown;

        while (!maxHeap.empty() || !cooldown.empty()) 
        {
            time++;

            if (!maxHeap.empty()) 
            {
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt -= 1;

                if (cnt > 0) 
                    cooldown.push({cnt, time + n});
            }

            // if task cooldown is finished, put task back into max heap
            if (!cooldown.empty() && cooldown.front().second == time) 
            {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};

// The optimal greedy approach 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequencies and sort by most frequent
        unordered_map<char, int> t_map;
        for (char t : tasks) {
            if (t_map.find(t) != t_map.end()) {
                t_map[t] += 1;
            } else {
                t_map[t] = 1;
            }
        }

        int max_freq = 0;
        for (auto& [task, freq] : t_map) {
            max_freq = max(max_freq, freq);
        }

        int max_count = 0;
        for (auto& [task, freq] : t_map) {
            if (freq == max_freq) {
                max_count++;
            }
        }

        // The intuition is really whether we can fill the gaps or not or whether
        // we have to idle
        return max((int)tasks.size(), ((max_freq - 1) * (n + 1) + max_count));
    }
};
