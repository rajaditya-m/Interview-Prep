class Solution:
    def maximalSquare(self, board):
        if not board:
            return 0
        nRows = len(board)
        nCols = len(board[0])
        maxSide = 0
        dpTable = [[0]*nCols for i in range(0, nRows)]
        for i in range(0, nRows):
            dpTable[i][0] = 1 if board[i][0] == '1' else 0
            if dpTable[i][0]>maxSide:
                maxSide=dpTable[i][0]
        for j in range(0, nCols):
            dpTable[0][j] = 1 if board[0][j] == '1' else 0
            if dpTable[0][j]>maxSide:
                maxSide=dpTable[0][j]
        for i in range(1, nRows):
            for j in range(1, nCols):
                if board[i][j] == '1':
                    dpTable[i][j] =  min(dpTable[i][j-1], dpTable[i-1][j], dpTable[i-1][j-1]) + 1
                    if dpTable[i][j]>maxSide:
                        maxSide=dpTable[i][j]
        return maxSide*maxSide

obj = Solution()
board = [[1, 0, 1, 0, 0],
[1, 0, 1, 1, 1],
[1, 1, 1, 1, 1],
[1, 0, 0, 1, 0]]
print(obj.maximalSquare(board))