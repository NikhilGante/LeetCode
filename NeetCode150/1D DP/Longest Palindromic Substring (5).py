class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        n = len(s)
        best_l, best_r = 0, 0
        for c in range(n):
            l, r = c, c
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l > best_r - best_l:
                    best_l, best_r = l, r
                l -= 1
                r += 1
            
            l, r = c, c + 1
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l > best_r - best_l:
                    best_l, best_r = l, r
                l -= 1
                r += 1
        return s[best_l : best_r + 1]