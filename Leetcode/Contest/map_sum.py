class MapSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}
        

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """
        cur = self.trie
        for ch in key:
            if not ch in cur:
                cur[ch] = {}
            cur = cur[ch]
        if '#' in cur:
            cur['#'] += val
        else:
            cur['#'] = val
        
        

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        cur = self.trie
        for ch in prefix:
            if not ch in cur:
                return 0
            cur = cur[ch]
        return self.allsum(cur)

    def allsum(self,trienode):
        ans = 0
        for key,value in trienode.items():
            if key=='#':
                ans += value
            else:
                ans += self.allsum(value)
        return ans

obj = MapSum()
obj.insert("apple", 3)
print(obj.sum("ap"))
obj.insert("app", 2)
print(obj.sum("ap"))

