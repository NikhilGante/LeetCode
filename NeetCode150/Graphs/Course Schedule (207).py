from typing import List
    
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Should be able to finish all courses as long as there aren't cycles
        adj = [[] for _ in range(numCourses)]
        for crs, pre in prerequisites: # Need to take b before a
            adj[crs].append(pre)

        def dfs(node: int):
            if path[node]:
                return False
            if vis[node]:   # if already visited, return immediately as this node already passed
                return True

            vis[node] = path[node] = True

            for nei in adj[node]:
                if not dfs(nei):
                    return False

            # Unmark trail after processing (to allow other branches to reach this node without failing)
            path[node] = False
            return True

        vis = [False] * numCourses
        path = [False] * numCourses # Which nodes we currently visit each cycle
        
        for crs in range(numCourses):
            if not dfs(crs):
                return False

        return True