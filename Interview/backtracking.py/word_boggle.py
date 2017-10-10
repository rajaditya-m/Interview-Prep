def wordBoggle(board, words):
    ans = []
    nr = len(board)
    if not nr:
        return []
    nc = len(board[0])
    for word in words:
        # print(word, board)
        found = False
        for r in range(nr):
            for c in range(nc):
                success = helper(board, word, r, c, nr, nc)
                if success:
                    ans.append(word)
                    found = True
                    break
            if found:
                break
    ans.sort()
    return ans
                    
        


def helper(board,word,r,c, nr, nc):
    if r>=nr or r<0 or c>=nc or c<0:
        return False
    if board[r][c]=='#':
        return False
    if word[0]!=board[r][c]:
        return False
    #change the identity to sentinel
    
    rem = word[1:]
    if rem:
        board[r][c] = '#'
        #conn 1
        s = helper(board,rem,r+1,c,nr,nc)
        if s:
            board[r][c] = word[0]
            return True
        s = helper(board,rem,r-1,c,nr,nc)
        if s:
            board[r][c] = word[0]
            return True
        s = helper(board,rem,r+1,c+1,nr,nc)
        if s:
            board[r][c] = word[0]
            return True
        s = helper(board,rem,r-1,c+1,nr,nc)
        if s:
            board[r][c] = word[0]
            return True
        s = helper(board,rem,r,c+1,nr,nc)
        if s:
            board[r][c] = word[0]
            return True
        s = helper(board,rem,r+1,c-1,nr,nc)
        if s:
            board[r][c] = word[0]
            return True
        s = helper(board,rem,r-1,c-1,nr,nc)
        if s:
            board[r][c] = word[0]
            return True
        s = helper(board,rem,r,c-1,nr,nc)
        if s:
            board[r][c] = word[0]
            return True
        board[r][c] = word[0]
        return False
    else:
        return True


    
board = [
    ['R', 'L', 'D'],
    ['U', 'O', 'E'],
    ['C', 'S', 'O']
]

word = ["RULES", "SOLO", "CODE", "COOL"]

print(wordBoggle(board, word))