class Solution:
    def countSubstrings(self, s: str) -> int:
        ans = 0
        n = len(s)
        for c in range(n):
            l, r = c, c
            while l >= 0 and r < n and s[l] == s[r]:
                ans += 1
                l -= 1
                r += 1
            
            l, r = c, c + 1
            while l >= 0 and r < n and s[l] == s[r]:
                ans += 1
                l -= 1
                r += 1
        return ans
