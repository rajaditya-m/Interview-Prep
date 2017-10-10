class MagicDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._trie = {}
        

    def buildDict(self, dict):
        """
        Build a dictionary through a list of words
        :type dict: List[str]
        :rtype: void
        """
        self._trie = {}
        for word in dict:
            cur = self._trie
            for c in word:
                if not c in cur:    
                    cur[c] = {}
                cur = cur[c]
            if '#' not in cur:
                cur['#'] = {}
        print(self._trie)

    def simplesearch(self, word, trie):
        cur_ptr = trie
        for ch in word:
            if ch in cur_ptr:
                cur_ptr = cur_ptr[ch]
            else:
                return False
        if '#' in cur_ptr:
            return True
        return False
        
    def search2(self, word):
        cur = self._trie
        for idx, ch in enumerate(word):
            for key,value in cur.items():
                    if key!=ch:
                        res = self.simplesearch(word[idx+1:],value)
                        if res:
                            # print(word[idx+1:],key,ch,value)
                            return True
            if ch in cur:
                cur = cur[ch]
            else:
                return False
        return False

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        modified = False
        cur = self._trie
        mismatch = -1
        for idx,char in enumerate(word):
            if char in cur:
                cur = cur[char]
            else:
                mismatch = idx
                break
        # print(mismatch)
        if mismatch==-1:
            return False
        remaining_word = word[mismatch+1:]
        # print(remaining_word)
        for key,value in cur.items():
            new_cur = value
            success = True
            for char in remaining_word:
                if char in new_cur:
                    new_cur = new_cur[char]
                else:
                    success = False
                    break
            if success and '#' in new_cur:
                return True
        return False
            

md = MagicDictionary()
md.buildDict(["hello", "hallo", "leetcode"])
print(md.search2("hello"))
print(md.search2("hhllo"))
print(md.search2("hell"))
print(md.search2("leetcoded"))