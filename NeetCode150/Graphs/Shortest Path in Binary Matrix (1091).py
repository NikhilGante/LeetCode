from typing import List
from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] or grid[n-1][n-1]:
            return -1

        q = deque([(0, 0)])
        grid[0][0] = 1  # store the distance IN the grid, saving memory

        directions = ((0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1))
        while q:
            cur_r, cur_c = q.popleft()
            dist = grid[cur_r][cur_c]
            if (cur_r, cur_c) == (n - 1, n - 1):
                return dist
            for dr, dc in directions:
                r, c = cur_r + dr, cur_c + dc
                if min(r, c) < 0 or max(r, c) >= n or grid[r][c]:
                    continue
                grid[r][c] = dist + 1
                q.append((r, c))

        return -1
