from typing import List
class Solution: # Space-optimized - O(n) space, O(n * m) space
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid[0]), len(grid)
        dp = [0] * (m + 1)
        dp[m-1] = 1
        for r in range(n - 1, -1, -1):
            for c in range(m - 1, -1, -1):
                if grid[r][c]:
                    dp[c] = 0
                else:
                    dp[c] += dp[c + 1]
        return dp[0]


class Solution2:    # Old solution
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