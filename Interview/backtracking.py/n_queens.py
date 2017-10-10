def noConflict(board, row, col):
    if not board:
        return True
    #check for row conflicts 
    if row in board:
        return False
    #row taste passed 
    for col_idx,row_idx in enumerate(board):
        col_idx += 1
        # print(col, col_idx)
        slope = (row-row_idx) / (col-col_idx)
        if slope ==1.0 or slope==-1.0:
            return False
    return True

def nQueens(n):
    ans = []
    helper(n, [], 1, ans )
    return ans
    
        

#tries to place a queen in the board
def helper(n, board, col, ans):
    if col>n:
        return
    for row in range(1,n+1):
        if noConflict(board, row, col):
            new_board = board[:]
            new_board.append(row)
            # print(new_board)
            helper(n, new_board, col+1, ans)
            if len(new_board)==n:
                #found a new config
                ans.append(new_board)
                return
    return

print(nQueens(1))