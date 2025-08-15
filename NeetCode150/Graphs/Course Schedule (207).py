from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        path = set()
        def dfs(node: int) -> bool:
            if node in path:
                return False
            path.add(node)
            for child in adj[node]:
                if not dfs(child):
                    return False
                
            path.remove(node)
            adj[node].clear()
            return True

        adj = [[] for _ in range(numCourses)]
        for pre in prerequisites: # Need to take b before a
            adj[pre[0]].append(pre[1])

        for node in range(len(adj)):
            if not dfs(node):
                return False

        return True