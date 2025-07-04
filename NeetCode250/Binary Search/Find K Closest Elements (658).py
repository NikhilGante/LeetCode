import heapq
from typing import List


# Heap solution
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        pq = []
        for num in arr:
            heapq.heappush(pq, (-abs(num - x), -num))
            if len(pq) > k:
                heapq.heappop(pq)

        return sorted([-num for _, num in pq])
