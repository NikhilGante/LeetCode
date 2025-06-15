from typing import List

class Solution:
    def dfs(self, coins: List[int], amount: int) -> int:
        if not amount:
            return 0
        if amount in self.memo:
            return self.memo[amount]
        min_coins = float('inf')
        for i in coins:
            if i <= amount:
                num_coins = self.dfs(coins, amount - i)
                if num_coins != -1:
                    min_coins = min(min_coins, 1 + num_coins)
        self.memo[amount] = -1 if min_coins == float('inf') else min_coins
        return self.memo[amount]

    def coinChange(self, coins: List[int], amount: int) -> int:
        self.memo = {}
        return  self.dfs(sorted(coins, reverse = True), amount)

    