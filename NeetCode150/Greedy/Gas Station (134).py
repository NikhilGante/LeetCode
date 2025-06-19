from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1

        net = 0
        ans = 0
        for i in range(len(gas)):
            net += gas[i] - cost[i]
            if net < 0:
                net = 0
                ans = i + 1
        return ans   

# Naive solution
class Solution2:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        map = {} # Start station, (end + 1, net cost)
        ans = 0
        i = 0
        n = len(gas)
        total = 0
        while total < n:
            curStart = i
            net = 0
            while net >= 0:
                if i in map:
                    net += map[i][1]
                    if net < 0: # not a valid shortcut if we run out of gas
                        break
                    newI = map[i][0]
                    if newI >= curStart:
                        if i > curStart:
                            if newI < i:
                                return curStart
                        else:
                            return curStart
                    i = newI
                else:    
                    net += gas[i] - cost[i]
                    total += 1
                    i = (i + 1) % n
                    if i == curStart and net >= 0: # not a valid shortcut if we run out of gas
                        return curStart
            map[curStart] = (i, net)
        return -1
