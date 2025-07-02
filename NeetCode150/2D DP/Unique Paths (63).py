from typing import List
class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        if grid[-1][-1]:
            return 0
        m, n = len(grid[0]), len(grid)
        prev = [0] * m
        prev[-1] = 1
        for c in range(m - 2, -1, -1):
            if not grid[-1][c]:
                prev[c] = prev[c + 1]
        for r in range(n - 2, -1, -1):
            row = [0] * m
            row[-1] = prev[-1]
            if grid[r][-1]:
                row[-1] = 0
            for c in range(m - 2, -1, -1):
                if not grid[r][c]:
                    row[c] = prev[c] + row[c + 1]  
            prev = row
        return prev[0]