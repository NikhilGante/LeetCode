class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * len(s)
        if s[-1] != '0':
            dp[0] = 1
        if n > 1 and s[-2] != '0':
            dp[1] = dp[0] + (1 if 1 <= int(s[-2] + s[-1]) <= 26 else 0)
        for i in range(2, n):
            j = n - i - 1
            if s[j] != '0':
                dp[i] = dp[i - 1] + (dp[i - 2] if 1 <= int(s[j] + s[j + 1]) <= 26 else 0)

        return dp[-1]
