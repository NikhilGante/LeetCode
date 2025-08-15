from typing import List

# Topological Sort
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        for pre in prerequisites:
            adj[pre[0]].append(pre[1])

        ans = []
        path, vis = set(), set()

        def dfs(node: int) -> bool:
            if node in path:
                return False # Cycle detected
            if node in vis:
                return True
            
            path.add(node)
            vis.add(node)

            for child in adj[node]:
                if not dfs(child):
                    return False

            path.remove(node)
            ans.append(node)
            return True

        for course in range(numCourses):
            if not dfs(course):
                return []
            
        return ans