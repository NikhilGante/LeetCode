import heapq
from typing import List

# Optimal solution O(log(n - k) + k)
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l, r = 0, len(arr) - k
        while l < r:
            m = (l + r) //2
            if x - arr[m] > arr[m + k] - x:
                l = m + 1
            else:
                r = m
        return arr[l: l + k]

# Heap solution
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        pq = []
        for num in arr:
            heapq.heappush(pq, (-abs(num - x), -num))
            if len(pq) > k:
                heapq.heappop(pq)

        return sorted([-num for _, num in pq])
