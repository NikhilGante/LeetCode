from typing import List
from collections import deque, defaultdict

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        n = len(equations)
        adj = defaultdict(list) # str -> list (node -> nei)
        for i in range(n):
            adj[equations[i][0]].append((equations[i][1], values[i]))
            adj[equations[i][1]].append((equations[i][0], 1/values[i]))

        def bfs(start: str, target: str):
            if start not in adj or target not in adj:
                return -1
            vis = set()
            q = deque([(start, 1.0)])
            while q:
                node, value = q.popleft()
                if node == target:
                    return value
                vis.add(node)

                for nei, val in adj[node]:
                    if nei not in vis:
                        q.append((nei, value * val))

            return -1.0

        return [bfs(a, b) for a,b in queries]