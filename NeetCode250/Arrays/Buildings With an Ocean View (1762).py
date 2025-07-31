from typing import List

class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        ans = []
        curMax = 0
        for i in range(len(heights) - 1, -1, -1):
            if heights[i] > curMax:
                ans.append(i)
                curMax = heights[i]
        ans.reverse()
        return ans