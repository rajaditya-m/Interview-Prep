class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.links = [None]*26
        self.terminal = False

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        if not word:
            self.terminal = True
            return
        char1 = word[0]
        rem = word[1:]
        idx = ord(char1)-ord('a')
        if not self.links[idx]:
            self.links[idx] = Trie() #create a new node
        self.links[idx].insert(rem)

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        if not word:
            if self.terminal:
                return True
            else:
                return False
        char1 = word[0]
        rem = word[1:]
        idx = ord(char1)-ord('a')
        if not self.links[idx]:
            return False
        else:
            return self.links[idx].search(rem)

class Solution(object):
    def findWords_NOREPEATS(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        if not board or not words:
            return []
        root = Trie()
        #first insert all the stuff in the trie 
        for word in words:
            root.insert(word)
        #next compute the dimensions of the grid 
        rowDim = len(board)
        colDim = len(board[0])
        visited = [[False]*colDim for i in range(0,rowDim)]
        for r in range(0,rowDim):
            for c in range(0, colDim):
                curWord = ''
                if not visited[r][c]:
                    # print('Seeding with <{},{}>'.format(r,c))
                    [success, retWord] = self.backtrackHelper(r, c, board, visited, root, rowDim, colDim, curWord)
                    # print(success, retWord)
                    if success:
                        print(retWord)
                        print(visited)

    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        if not board or not words:
            return []
        resultWords = []
        root = Trie()
        #first insert all the stuff in the trie 
        for word in words:
            root.insert(word)
        #next compute the dimensions of the grid 
        rowDim = len(board)
        colDim = len(board[0])
        answer = set()
        for r in range(0,rowDim):
            for c in range(0, colDim):
                visited = [[False]*colDim for i in range(0,rowDim)]
                seedWord = ''
                self.backtrackHelper_v2(root, board, r, c, visited, seedWord, answer )
                #print(answer)
        return list(answer)

    def backtrackHelper_v2(self, root, board, rowSeed, colSeed, visited, word, answer):
        #Base case 1: Board Dimensions exceeded
        if root.terminal:
            answer.add(word)
        if rowSeed<0 or rowSeed>=len(board) or colSeed<0 or colSeed>=len(board[0]):
            return
        char = board[rowSeed][colSeed]
        idx = ord(char)-ord('a')
        if not visited[rowSeed][colSeed] and root.links[idx]:
            curWord = word+char
            visited[rowSeed][colSeed] = True
            #now we will explore hierarchically if any of the surrounding unvisited characters occur in the neighbourhood of the trie
            self.backtrackHelper_v2(root.links[idx], board, rowSeed+1, colSeed, visited, curWord, answer)
            self.backtrackHelper_v2(root.links[idx], board, rowSeed-1, colSeed, visited, curWord, answer)
            self.backtrackHelper_v2(root.links[idx], board, rowSeed, colSeed+1, visited, curWord, answer)
            self.backtrackHelper_v2(root.links[idx], board, rowSeed, colSeed-1, visited, curWord, answer)
            visited[rowSeed][colSeed]= False

        

obj = Solution()
# board = [
#   ['o','a','a','n'],
#   ['e','t','a','e'],
#   ['i','h','k','r'],
#   ['i','f','l','v']
# ]
# words = ["oath","pea","eat","rain"]
# board = [
#   ['a']
# ]
# words = ["a"]
board = ["ab","cd"]
words = ["ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"]
print(obj.findWords(board, words))