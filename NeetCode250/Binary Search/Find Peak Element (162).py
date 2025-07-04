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

# Simpler but not logn I suppose
class Solution2:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) //2
            if nums[r] > nums[mid]:
                l = mid + 1
            elif nums[l] > nums[mid]:
                r = mid - 1
            else:
                r-=1
        return mid
 
