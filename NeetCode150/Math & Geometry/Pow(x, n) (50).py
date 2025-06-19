class Solution:
    def myPow(self, x: float, n: int) -> float: # Recursive Solution runs in logn instead of linear time
        if n == 0:  # Base Case
            return 1
        
        if n < 1:
            return 1/self.myPow(x, -n)
        # (Positive) Recursive Cases
        res = self.myPow(x, n//2)
        res *= res # res^2
        return res * x if n & 1 else res