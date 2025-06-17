from typing import List

class Solution:
    def isPal(self, s: str, l: int, r: int) -> bool:
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    def partition(self, s: str) -> List[List[str]]:
        ans = []   # list of lists of strs
        arr = []   # Current list to be appended
        n = len(s)
        def helper(i: int): # dfs
            if i >= n:
                ans.append(arr.copy())
                return
            
            for sub in range(i, n):
                cur = s[i : sub + 1]
                if self.isPal(s, i, sub):
                    arr.append(cur)
                    helper(sub + 1)
                    arr.pop()

        helper(0)
        return ans
