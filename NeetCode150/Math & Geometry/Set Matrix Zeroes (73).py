from typing import List

# Simpler Solution using sets O(n + m) space
class Solution2:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows, cols = set(), set()
        m, n = len(matrix[0]), len(matrix)
        for r in range(n):
            for c in range(m):
                if not matrix[r][c]:
                    rows.add(r)
                    cols.add(c)

        for r in rows:
            for c in range(m):
                matrix[r][c] = 0

        for c in cols:
            for r in range(n):
                matrix[r][c] = 0