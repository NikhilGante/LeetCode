class Solution:
    def isHappy(self, n: int) -> bool:
        def findSumOfSquares(val):
            ans = 0
            while val:
                val, cur = divmod(val, 10)
                ans += cur * cur
            return ans

        vis = set()
        while(n != 1):
            n = findSumOfSquares(n)
            if n in vis:
                return False
            vis.add(n)
        return True