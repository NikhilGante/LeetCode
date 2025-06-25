from typing import List

# Optimized using 2d bool arrays as hashmaps of hashsets
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [[False] * 9 for _ in range(9)]
        cols = [[False] * 9 for _ in range(9)]
        squares = [[False] * 9 for _ in range(9)]

        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    continue
                cur = int(board[r][c]) - 1
                
                if rows[r][cur] or cols[c][cur] or squares[3*(r//3) + c//3][cur]:
                    return False
                
                rows[r][cur] = cols[c][cur] = squares[3*(r//3) + c//3][cur] = True

        return True
    
class Solution2:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        s = set()
        print(board)

        for r in range(9):
            s.clear()
            for c in range(9):
                if board[r][c] != '.' and board[r][c] in s:
                    return False
                s.add(board[r][c])

        for c in range(9):
            s.clear()
            for r in range(9):
                if board[r][c] != '.' and board[r][c] in s:
                    return False
                s.add(board[r][c])

        for big_r in range(3):
            for big_c in range(3):
                s.clear()
                for r in range(big_r*3, big_r*3 + 3):
                    for c in range(big_c*3, big_c*3 + 3):
                        if board[r][c] in s and board[r][c] != '.':                        
                            return False
                        s.add(board[r][c])
        return True