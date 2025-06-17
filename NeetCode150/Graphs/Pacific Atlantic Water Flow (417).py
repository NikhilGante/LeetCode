from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights[0]), len(heights)

        pac, atl = set(), set()
        ans = []
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        def dfs(r, c, s):
            pac, atl = False, False
            s.add((r, c))
            # print(f"at {r, c}, {pac, atl}")

            cur_height = heights[r][c]
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                # print(f'\ttrying {nr, nc}')
                if (0 <= nr < n) and (0 <= nc < m):
                    if heights[nr][nc] >= cur_height and (nr, nc) not in s:
                        dfs(nr, nc, s)
                #         print("\t\tsucc")
                #     else:
                #         print(f'\t\tToo short or alr seen {heights[r][c]}')
                # else:
                #     print('\t\tfail')
                        
        for r in range(n):
            dfs(r, 0, pac)
            dfs(r, m - 1, atl)
        for c in range(m):
            dfs(0, c, pac)
            dfs(n - 1, c, atl)
        
        for r in range(n):
            for c in range(m):
                if (r, c) in pac and (r, c) in atl:
                    ans.append((r, c))
        return ans


