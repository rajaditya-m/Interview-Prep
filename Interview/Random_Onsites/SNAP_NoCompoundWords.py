class Solution:
    def SNAP_noCompoundWords(self, words):
        trie = {}
        for word in words:
            cur = trie
            if word:
                for letter in word:
                    if not letter in cur:
                        cur[letter] = {}
                    cur = cur[letter]
            cur['#'] = '.'
        print(trie)

obj = Solution()
word = ['super', 'soup', 'sexy', 'pants']
obj.SNAP_noCompoundWords(word)
    