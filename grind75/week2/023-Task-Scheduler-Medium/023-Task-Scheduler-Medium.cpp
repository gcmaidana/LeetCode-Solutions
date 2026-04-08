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
        // Count frequencies
        unordered_map<char, int> tMap;
        for (char t : tasks) 
        {
            if (tMap.find(t) != tMap.end()) 
            {
                tMap[t] += 1;
            } 
            else 
            {
                tMap[t] = 1;
            }
        }

        int maxFreq = 0;
        for (auto& [task, freq] : tMap) 
            maxFreq = max(maxFreq, freq);
        

        int maxCount = 0;
        for (auto& [task, freq] : tMap) 
        {
            if (freq == maxFreq) 
                maxCount++;
        }

        // The intuition is really whether we can fill the gaps or not or whether
        // we have to idle
        return max((int)tasks.size(), ((maxFreq - 1) * (n + 1) + maxCount));
    }
};
