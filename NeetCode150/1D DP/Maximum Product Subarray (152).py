from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ma, mi = 1, 1
        ans = nums[0]
        for n in nums:
            temp = ma
            ma = max(n, ma*n, mi * n)
            mi = min(n, mi*n, temp * n)
            ans = max(ans, ma)
        return ans