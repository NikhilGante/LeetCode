from typing import List
import heapq

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        pq = [(0, points[0][0], points[0][1])]
            
        # print(pq)
        vis = set()
        minCost = 0

        while len(vis) < n:
            w, xi, yi = heapq.heappop(pq)
            if (xi, yi) in vis:
                continue

            # Process node
            minCost += w
            vis.add((xi, yi))

            for x, y in points:
                if (x, y) not in vis:
                    heapq.heappush(pq, (abs(xi - x) + abs(yi - y), x, y))

        return minCost