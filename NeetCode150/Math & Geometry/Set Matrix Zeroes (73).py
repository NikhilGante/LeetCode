from typing import List

# "Space optimal solution" - uses top and left cols of matrix as bool sets
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m, n = len(matrix[0]), len(matrix)
        top, left = False, False
    
        for r in range(n):
            if not matrix[r][0]:
                left = True
        for c in range(m):
            if not matrix[0][c]:
                top = True


        for r in range(1, n):
            for c in range(1, m):
                if not matrix[r][c]:
                    matrix[0][c] = 0
                    matrix[r][0] = 0


        for r in range(1, n):
            if not matrix[r][0]:
                for c in range(1, m):
                    matrix[r][c] = 0

        for c in range(1, m): # Cols
            if not matrix[0][c]:
                for r in range(1, n):
                    matrix[r][c] = 0

        if top:
            for c in range(m):
                matrix[0][c] = 0
        if left:
            for r in range(n):
                matrix[r][0] = 0

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