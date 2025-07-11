from typing import List

# DFS Solution (Suboptimal)
class Solution2:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid[0]), len(grid)
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        visited = [[False] * m for _ in range(n)]

        def dfs(r, c):
            visited[r][c] = True
            
            ans = 4 # Num of perimeter lines, assume 4 to start off
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m and grid[nr][nc]:
                    ans -= 1 # Each neighbour means one less perimeter line
                    if not visited[nr][nc]:
                        ans += dfs(nr, nc)
            return ans

        for r in range(n):
            for c in range(m):
                if grid[r][c]:
                    return dfs(r, c)
        return -1