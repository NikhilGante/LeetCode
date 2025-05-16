from typing import List

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pairs = sorted(zip(position, speed), reverse = True)

        prev_eta = 0
        num_fleets = 0
        for p, s in pairs:
            eta = (target - p) / s
            if eta > prev_eta: # New Fleet
                num_fleets += 1
                prev_eta = eta
        return num_fleets + 1