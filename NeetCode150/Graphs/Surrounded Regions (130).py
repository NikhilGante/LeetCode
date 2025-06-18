from typing import List

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        m, n = len(board[0]), len(board)

        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        vis = set()
        def dfs(r, c): 
            if not (0 <= r < n) or not (0 <= c < m) or board[r][c] == 'X' or (r, c) in vis:
                return True
            surrounded = True
            vis.add((r, c))
            if not r or r == n - 1 or not c or c == m - 1:    # On the edge of board
                surrounded = False
            
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                surrounded &= dfs(nr, nc)
            return surrounded
            
            
        for r in range(1, n - 1):
            for c in range(1, m - 1):
                vis.clear()
                if dfs(r, c):
                    for _r, _c in vis:
                        board[_r][_c] = 'X'


