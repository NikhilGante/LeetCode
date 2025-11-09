from typing import List
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        adj = [[] for _ in range(n)]    # Convert to adj list
        for u, v, w in times:
            adj[u - 1].append((v - 1, w))

        pq = [(0, k - 1)]   # time, node
        vis = [False] * n
        numVis = 0
        t = 0
        while pq and numVis < n:
            t, n1 = heapq.heappop(pq)
            if vis[n1]:
                continue

            numVis += 1
            vis[n1] = True
            for n2, w in adj[n1]:
                if not vis[n2]:
                    heapq.heappush(pq, (t + w, n2))
        
        return t if numVis == n else -1