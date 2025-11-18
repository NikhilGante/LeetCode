from typing import List

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        adj = [True] * n
        for u, v in edges:
            adj[v] = False # Node v can't have indegree > 0 to be a champion
        
        found = False
        ans = -1
        for node in range(n):
            if adj[node]:
                if found:
                    return -1
                found = True
                ans = node
        return ans
