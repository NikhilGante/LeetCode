from typing import List
class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid[0]), len(grid)
        prev = [0] * m
        prev[-1] = 1 # Assume at least one path to bottom-right
        for r in range(n - 1, -1, -1):
            row = [0] * m
            row[-1] = prev[-1] if not grid[r][-1] else 0
            for c in range(m - 2, -1, -1):
                if not grid[r][c]:
                    row[c] = prev[c] + row[c + 1]  
            prev = row
        return prev[0]