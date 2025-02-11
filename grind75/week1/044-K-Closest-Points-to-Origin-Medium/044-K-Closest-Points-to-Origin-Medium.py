# Question link: https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        minHeap  = []
        res = []

        for x, y in points:

            z = (x ** 2) + (y ** 2)
            minHeap.append((z, x, y))
        
        heapq.heapify(minHeap)

        while k > 0:
            z, x, y = heapq.heappop(minHeap)

            res.append((x, y))
            k -= 1
        return res
  


