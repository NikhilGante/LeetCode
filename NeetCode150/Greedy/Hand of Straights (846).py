from typing import List
from collections import Counter
import heapq

# O(logn) solution
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        
        # 2 cases we ret false - a) can't find target or b) when freq of value goes to 0 and val is not the min
        freq = Counter(hand)
        pq = list(freq.keys())
        heapq.heapify(pq)        
        while pq:
            first = pq[0]
            for target in range(first, first + groupSize):
                if target not in freq:
                    return False
                freq[target] -= 1
                if not freq[target]:
                    if target != pq[0]: # b) when freq of value goes to 0 and val is not the min
                        return False
                    heapq.heappop(pq)

        return True
        


# Suboptimal solution (using ordered property of hashset)
class Solution2:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize:
            return False
        
        hand.sort()
        freq = {}
        for card in hand:
            freq[card] = freq.get(card, 0) + 1


        while freq:
            group = []
            for card in freq:
                group.append(card)
                freq[card] -= 1
                if not freq[card]:
                    del freq[card]
                break
            while len(group) < groupSize:
                target = group[-1] + 1
                found = False
                for card in freq:
                    if card > target:
                        return False        # can't form group
                    if card < target:
                        continue
                    group.append(card)
                    found = True
                    target = group[-1] + 1

                    freq[card] -= 1
                    if not freq[card]:
                        del freq[card]
                        break    # dict size change
                    if len(group) == groupSize:
                        break
                if not found:
                    return False

        return True