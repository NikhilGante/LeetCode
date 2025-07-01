class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        prev = [0] * n # row below
        for r in range(m - 1, -1, -1):
            row = [0] * n
            row[-1] = 1
            for c in range(n - 2, -1, -1):
                row[c] += row[c + 1] + prev[c]
            prev = row
        return prev[0]
