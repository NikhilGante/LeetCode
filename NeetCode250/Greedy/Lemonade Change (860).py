from typing import List

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        n5, n10 = 0, 0
        for bill in bills:
            match(bill):
                case 5:
                    n5 += 1
                case 10:
                    n10 += 1
                    if not n5:
                        return False
                    n5 -= 1
                case 20:
                    if n5 and n10:
                        n5 -= 1
                        n10 -= 1 
                    elif n5 >= 3:
                        n5 -= 3
                    else:
                        return False

        return True