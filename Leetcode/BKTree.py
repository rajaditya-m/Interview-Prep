class BK_Tree_Node:
    def __init__(self, word):
        self._word = word
        self._maps = {}

    def printRec(self):
        print(self._word)
        print('{')
        for key,values in self._maps.items():
            print('key:'+str(key))
            values.printRec()
        print('}')
    
    def insert(self, word):
        l_dist = self.levenstein_distance(word,self._word)
        if l_dist in self._maps:
            self._maps[l_dist].insert(word)
        else:
            self._maps[l_dist] = BK_Tree_Node(word)

    def search(self, word, tolerance):
        l_dist = self.levenstein_distance(word, self._word)
        if l_dist == tolerance:
            print(self._word)
        lower = l_dist - tolerance
        upper = l_dist + tolerance
        for i in range(lower,upper+1):
            if i in self._maps:
                self._maps[i].search(word, tolerance)

    def levenstein_distance(self, a, b):
        m = len(a)
        n = len(b)
        table = [[0]*(n+1) for _ in range(m+1)]
        delcost = 1
        addcost = 1
        subcost = 1
        for i in range(m+1):
            table[i][0] = i * delcost
        for j in range(n+1):
            table[0][j] = j * addcost
        for i in range(1, m+1):
            for j in range(1, n+1):
                if a[i-1] == b[j-1]:
                    table[i][j] = table[i-1][j-1]
                else:
                    table[i][j] = min(table[i-1][j] + delcost, table[i][j-1] + addcost, table[i-1][j-1] + subcost)
        return table[m][n]



class BK_Tree():
    def __init__(self):
        self._root = None
        self._tolerance = 1
    
    def insert(self, word):
        if not self._root:
            self._root = BK_Tree_Node(word)
        else:
            self._root.insert(word)
    
    def printTree(self):
        if self._root:
            self._root.printRec()

    def search(self,word):
        if self._root:
            self._root.search(word,self._tolerance)
        



     

bktree = BK_Tree()
wlist = ['book', 'books', 'cake', 'boo', 'cape', 'boon', 'cook', 'cart']
for w in wlist:
    bktree.insert(w)
target = 'caqe'
bktree.search(target)