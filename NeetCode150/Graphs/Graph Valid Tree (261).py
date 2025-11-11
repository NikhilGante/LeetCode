from typing import List
from collections import defaultdict

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) > n - 1:
            return False
        
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        vis = [False] * n
        numVis = 0
        def dfs(node: int, par: int) -> bool: # Return false if cyclic (i.e. we've already visited it before)
            if vis[node]:
                return False
            vis[node] = True
            nonlocal numVis
            numVis += 1
            for nei in adj[node]:
                if nei != par and not dfs(nei, node):
                    return False
            return True
        
        return dfs(0, -1) and numVis == n   # Check that graph is both acyclic and connected
