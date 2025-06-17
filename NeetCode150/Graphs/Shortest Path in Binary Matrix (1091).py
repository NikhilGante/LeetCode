from typing import List
from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        if grid[0][0]:
            return -1

        n = len(grid)
        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True

        q = deque()
        q.append((0, 0))

        directions = ((0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1))
        dist = 1
        while q:
            for _ in range(len(q)):
                cur_r, cur_c = q.popleft()

                if (cur_r, cur_c) == (n - 1, n - 1):
                    return dist
                for dr, dc in directions:
                    r, c = cur_r + dr, cur_c + dc
                    if min(r, c) < 0 or max(r, c) >= n or grid[r][c] == 1 or visited[r][c]:
                        continue
                    visited[r][c] = True
                    q.append((r, c))
            dist += 1

        return -1
