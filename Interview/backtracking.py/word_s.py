def dfs(board, word, visited,r,c):
    fc = word[0]
    rem = word[1:]
    if board[r][c]==fc:
        if not rem:
            return True
        visited[r][c]=True
        if r+1<len(board) and not visited[r+1][c]:
            copy_visited_1 = copy.deepcopy(visited)
            r1 = dfs(board, rem, copy_visited_1, r+1,c) 
            if r1:
                return True
        if c+1<len(board[0]) and not visited[r][c+1]:
            copy_visited_2 = copy.deepcopy(visited)
            r2 = dfs(board, rem, copy_visited_2, r, c+1)
            if r2:
                return True
        if r-1>=0 and not visited[r-1][c]:
            copy_visited_3 = copy.deepcopy(visited)
            r3 = dfs(board, rem, copy_visited_3, r-1, c)
            if r3:
                return True
        if c-1>=0 and not visited[r][c-1]:
            copy_visited_4 = copy.deepcopy(visited)
            r4 = dfs(board, rem, copy_visited_4, r, c-1)
            if r4:
                return True
    return False
    
def boggle_search(board,word):
    nr = len(board)
    nc = len(board[0])
    for r in range(0,nr):
        for c in range(0, nc):
            dfs_visited = [ [False]*nc for _ in range(nr)]
            bt = dfs(board, word, dfs_visited,r,c)
            if bt:
                return True
    return False

board = [
['A','F','A','J'],
['S','I','V','A'],
['E','R','O','C'],
['C','X','E','K'],
['O','D','F','S'],
['D','E','E','E']
]

wprd = 'SEE'

print(boggle_search(board, wprd))
