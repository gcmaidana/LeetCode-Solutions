# https://leetcode.com/problems/task-scheduler/

# Max heap approach (less efficient)
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Sort by freq (largest to smallest), use maxHeap and q
        # when we process a task, we add it to the q along with the time that the task is done
        count = Counter(tasks)
        maxHeap = [-cnt for cnt in count.values()]
        heapq.heapify(maxHeap)

        time = 0
        q = deque() # pair is -cnt and idleTime

        while maxHeap or q:
            time += 1

            if maxHeap:
                cnt = 1 + heapq.heappop(maxHeap)
                if cnt:
                    q.append([cnt, time + n])

            if q and q[0][1] == time:
                heapq.heappush(maxHeap, q.popleft()[0])
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
