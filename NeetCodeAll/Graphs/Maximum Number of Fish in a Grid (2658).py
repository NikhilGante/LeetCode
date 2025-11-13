from typing import List
from collections import deque

class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        vis = [[False] * n for _ in range(m)]

        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        def bfs(row, col):
            q = deque()
            q.append((row, col))
            vis[row][col] = True
            maxFish = 0
            while q:
                r, c = q.popleft()
                maxFish += grid[r][c]
                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and not vis[nr][nc] and grid[nr][nc]:
                        q.append((nr, nc))
                        vis[nr][nc] = True
            return maxFish

        ans = 0
        for row in range(m):
            for col in range(n):
                if not vis[row][col] and grid[row][col]:
                    ans = max(ans, bfs(row, col))
        return ans