from typing import List
from collections import defaultdict

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)):
            if i and nums[i] == nums[i - 1]:
                continue

            l, r = i + 1, len(nums) - 1

            target = -nums[i]
            while l < r:
                combined = nums[l] + nums[r]
                if combined < target:
                    l += 1
                elif combined > target:
                    r -= 1
                else:
                    ans.append([nums[i], nums[l], nums[r]]) # Don't break here, there can be more combinations
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return ans

# Suboptimal solution (with hashing)

class Solution2:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        mp = {}
        ans = set()
        for i, val in enumerate(nums):
            if val not in mp:
                mp[val] = []
            mp[val].append(i)

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] or nums[j]:          # Skip 0, 0 combinations
                    complement = -(nums[i] + nums[j])
                    if complement in mp:
                        for k in mp[complement]:
                            if k != i and k != j:
                                ans.add(tuple(sorted([nums[i], nums[j], nums[k]])))
                                break

        if len(mp.get(0, [0])) >= 3:
            ans.add((0, 0, 0))
    
        return list(ans)