from typing import List

class Solution:
    def isPal(self, s: str) -> bool:
        for c in range(len(s) // 2):
            if s[c] != s[-c - 1]:
                return False
        return True

    def helper(self, s: str, arr: list): # dfs
        if not s:
            self.ans.append(arr.copy())
            return
        
        for sub in range(1, len(s) + 1):
            cur = s[:sub]
            if self.isPal(cur):
                arr.append(cur)
                self.helper(s[sub::], arr)
                arr.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.ans = []   # list of lists of strs
        self.helper(s, [])
        return self.ans