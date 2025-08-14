from typing import List
import heapq

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        m, n = len(grid[0]), len(grid)

        directions = ((0, 1), (0, -1), (1, 0), (-1,0))
        q = [(grid[0][0], 0, 0)]
        grid[0][0] = -1

        ans = 0
        while q:
            height, r, c = heapq.heappop(q)
            ans = max(height, ans)
            if r == n - 1 and c == m - 1:
                return ans
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] != -1:
                    grid[r][c] = -1 # mark as visited
                    heapq.heappush(q, (grid[nr][nc], nr, nc))

        return -1        