from typing import List
from math import ceil
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # def calcTime(speed: int) -> int:
        #     t = 0 # total time
        #     for pile in piles:
        #         t += ceil(pile/speed)
        #     return t
    
        best_rate = max(piles)
        l, r = 1, best_rate
        while l <= r:
            mid = l + (r - l) // 2
            t = 0 # total time
            for pile in piles:
                t += ceil(pile/mid)
            if t <= h:  # Counterintuitively, if our guessed time underestimates, we DECREMENT the RATE
                r = mid - 1
                best_rate = mid # If estimated time < target, it's valid, so we save it in case we overshoot
            elif t > h:
                l = mid + 1
        return best_rate
