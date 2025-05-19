from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        ans = nums[0] + nums[1] + nums[2]
        for i in range(n):
            if i and nums[i] == nums[i - 1]:
                continue

            l, r = i + 1, n - 1
            while l < r:
                combined = nums[i] + nums[l] + nums[r]
                if abs(combined - target) < abs(ans - target):
                    ans = combined

                if combined < target:
                    l += 1
                elif combined > target:
                    r -= 1
                else:
                    return combined

        return ans