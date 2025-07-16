from typing import List

class Solution:

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # Convert 1d to 2d index: [index//width, index%width]
        w = len(matrix[0]) 
        l, r = 0, len(matrix) * w - 1

        while l <= r:
            mid = l + (r - l) // 2
            mid_val = matrix[mid // w][mid % w]
            if mid_val > target:
                r = mid - 1
            elif mid_val < target:
                l = mid + 1
            else:
                return True
        return False
