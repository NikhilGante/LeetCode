from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:  return 0

        l, r = 0, n - 1

        while l <= r:
            mid = (l + r) // 2
            cur = nums[mid]
            
            if mid < n - 1 and nums[mid + 1] > cur:
                l = mid + 1
            elif mid and nums[mid - 1] > cur:
                r = mid - 1
            else:
                return mid    
        return mid
    