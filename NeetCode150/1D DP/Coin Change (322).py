from typing import List

# Tabulation (Bottom up) approach
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort()
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for num in range(1, amount + 1):
            for coin in coins:
                if coin > num:
                    break
                elif coin == num:
                    dp[num] = 1
                else:
                    dp[num] = min(dp[num], 1 + dp[num - coin])
        return -1 if dp[-1] == amount + 1 else dp[-1]

# Top-down Memo Solution

# class Solution:
#     def dfs(self, coins: List[int], amount: int) -> int:
#         if not amount:
#             return 0
#         if amount in self.memo:
#             return self.memo[amount]
#         min_coins = float('inf')
#         for i in coins:
#             if i <= amount:
#                 num_coins = self.dfs(coins, amount - i)
#                 if num_coins != -1:
#                     min_coins = min(min_coins, 1 + num_coins)
#         self.memo[amount] = -1 if min_coins == float('inf') else min_coins
#         return self.memo[amount]

#     def coinChange(self, coins: List[int], amount: int) -> int:
#         self.memo = {}
#         return  self.dfs(sorted(coins, reverse = True), amount)

    