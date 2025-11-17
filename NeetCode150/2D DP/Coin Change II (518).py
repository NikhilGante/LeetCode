from typing import List
import heapq


# Space-optimized solution: O(m * n) time, O(m) space, where m is amount, n is len(coins)
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # dp[r][c] -> (r -> are able to use coins[0 to r], c -> generate value c)
        dp = [0] * (amount + 1)
        dp[0] = 1        # 1 way to generate value of 0, use none of the coins

        for r in range(len(coins)):
            curCoin = coins[r]
            prev = dp
            dp[0] = 1        # 1 way to generate value of 0, use none of the coins
            for c in range(1, amount + 1):
                skip = prev[c]
                include = dp[c - curCoin] if c >= curCoin else 0
                dp[c] = skip + include

        return  dp[-1]
    

# O(m * n) time, O(m * n) space, where m is amount, n is len(coins)
class Solution2:
    def change(self, amount: int, coins: List[int]) -> int:
        # dp[r][c] -> (r -> are able to use coins[0 to r], c -> generate value c)
        dp = [[0] * (amount + 1) for _ in coins]
        for c in range(amount + 1):  # init first row
            if c % coins[0] == 0:
                dp[0][c] = 1

        for r in range(len(coins)):  # Init first column
            dp[r][0] = 1        # 1 way to generate value of 0, use none of the coins

        for r in range(1, len(coins)):
            curCoin = coins[r]
            for c in range(1, amount + 1):
                skip = dp[r - 1][c]
                include = dp[r][c - curCoin] if c >= curCoin else 0
                dp[r][c] = skip + include

        return  dp[-1][-1]