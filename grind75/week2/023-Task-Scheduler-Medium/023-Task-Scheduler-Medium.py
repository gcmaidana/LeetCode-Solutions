# https://leetcode.com/problems/task-scheduler/

# Max heap approach (less efficient)
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Sort by freq (largest to smallest), use maxHeap and q
        # when we process a task, we add it to the q along with the time that the task is done
        count = Counter(tasks)
        max_heap = [-cnt for cnt in count.values()]
        heapq.heapify(max_heap)

        time = 0
        cooldown = deque() # [remaining_count, available_time]

        while max_heap or cooldown:
            time += 1

            if max_heap:
                cnt = 1 + heapq.heappop(max_heap)
                if cnt:
                    cooldown.append([cnt, time + n])

            # if task cooldown is finished, put task back into q
            if cooldown and cooldown[0][1] == time:
                heapq.heappush(max_heap, cooldown.popleft()[0])
        return time

# Most optimal approach
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Count frequencies and sort by most frequent
        t_map = {}
        for t in tasks:
            if t in t_map:
                t_map[t] += 1
            else:
                t_map[t] = 1
        
        max_freq = max(t_map.values())
        max_count = list(t_map.values()).count(max_freq)

        # The intuition is really whether we can fill the gaps or not or whether
        # we have to idle
        return max(len(tasks), ((max_freq - 1) * (n + 1) + max_count))
