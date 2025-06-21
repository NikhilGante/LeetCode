from typing import List

# Naive O(nlogn) sol
class Solution2:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n + 1)
        for i in range(n + 1):
            count = 0
            val = i
            while val:
                if val & 1:
                    count += 1
                val >>= 1
            ans[i] = count
        return ans