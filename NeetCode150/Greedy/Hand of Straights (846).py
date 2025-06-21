from typing import List


# Suboptimal solution
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