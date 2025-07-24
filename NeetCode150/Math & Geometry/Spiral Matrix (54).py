from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix[0]), len(matrix)

        r, d, l, u = m - 1, n - 1, 0, 1 # Bounds
        ans = [0] * (m * n)
        ans[0] = matrix[0][0]
        y, x = 0, 0
        i = 1
        while i < len(ans):
            while x < r and i < len(ans):
                x += 1
                ans[i] = matrix[y][x] 
                i += 1
            r -= 1
            while y < d and i < len(ans):
                y += 1
                ans[i] = matrix[y][x] 
                i += 1
            d -= 1
            while x > l and i < len(ans):
                x -= 1
                ans[i] = matrix[y][x] 
                i += 1
            l += 1
            while y > u and i < len(ans):
                y -= 1
                ans[i] = matrix[y][x] 
                i += 1
            u += 1
        return ans