from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1] * i for i in range(1, numRows + 1)]
        for r in range(1, numRows):
            ans[r][0] = ans[r - 1][0]
            ans[r][-1] = ans[r - 1][-1]
            for c in range(1, len(ans[r]) - 1):
                ans[r][c] = ans[r - 1][c - 1] + ans[r - 1][c]
        return ans
