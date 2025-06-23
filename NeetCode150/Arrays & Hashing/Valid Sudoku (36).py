from typing import List

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