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

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        if not prefix:
            return True
        char1 = prefix[0]
        rem = prefix[1:]
        idx = ord(char1)-ord('a')
        if not self.links[idx]:
            return False
        else:
            return self.links[idx].startsWith(rem)

    def wildCardMatchingRestricted(self, wildcard):
        """
        Returns if there is any word in the trie that starts with the given wildcard only . is supported
        :type prefix: str
        :rtype: bool
        """
        if not wildcard:
            if self.terminal:
                return True
            else:
                return False
        char1 = wildcard[0]
        rem = wildcard[1:]
        if char1=='.':
            for lnk in self.links:
                if lnk:
                    searchSuccess = lnk.wildCardMatchingRestricted(rem)
                    if searchSuccess:
                        return True
            return False
        else:
            idx = ord(char1)-ord('a')
            if not self.links[idx]:
                return False
            else:
                return self.links[idx].wildCardMatchingRestricted(rem)
        
        

root = Trie()
root.insert('setang')
root.insert('pussy')
root.insert('set')

print(root.wildCardMatchingRestricted('p..sy'))    