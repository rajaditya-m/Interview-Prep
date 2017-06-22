class Solution:
    def solve(self, board):
        if not board:
            return 
        self.nRows = len(board)
        self.nCols = len(board[0])
        for r in range(0, self.nRows):
            self.dfsHelper(r, 0, board)
            self.dfsHelper(r, self.nCols-1, board)
        for c in range(1, self.nCols-1):
            self.dfsHelper(0, c, board)
            self.dfsHelper(self.nRows-1, c, board)
        for r in range(0, self.nRows):
            for c in range(0, self.nCols):
                if board[r][c]=='b':
                    board[r][c] = 'o'
                elif board[r][c] == 'o':
                    board[r][c] = 'x'
        
    
    def dfsHelper(self, r, c, board):
        if r < 0 or r >= self.nRows or c < 0 or c >= self.nCols:
            return
        if board[r][c]=='o':
            board[r][c] = 'b'
            self.dfsHelper(r+1, c, board)
            self.dfsHelper(r-1, c, board)
            self.dfsHelper(r, c+1, board)
            self.dfsHelper(r, c-1, board)

obj = Solution()
board = [['x','x','x','x'],
         ['x','o','o','x'],
         ['x','x','o','x'],
         ['x','x','x','x'],
         ['x','o','x','x']]
obj.solve(board)
print(board)
