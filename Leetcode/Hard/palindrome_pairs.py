class Solution:

    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        table = {}
        revTable = {}
        empty = []
        self_palindromes = []
        answer = []
        for idx, word in enumerate(words):
            # print(word)
            revWord = word[::-1]
            if not word:
                empty.append(idx)
                continue
            if word==revWord:
                self_palindromes.append(idx)
            if word[0] in table:
                table[word[0]].append(idx)
            else:
                table[word[0]] = [idx]
            if revWord[0] in revTable:
                revTable[revWord[0]].append(idx)
            else:
                revTable[revWord[0]] = [idx]
        for i, word in enumerate(words):
            if not word:
                continue
            if word[0] in  revTable:
                idx_b = revTable[word[0]]
                for j in idx_b:
                    wordj = words[j]
                    concat = word + wordj
                    if concat==concat[::-1]:
                        if i!=j :
                            answer.append([i,j])
        for eidx in empty:
            for spidx in self_palindromes:
                answer.append([eidx, spidx])
                answer.append([spidx, eidx])
        return answer



words = ["a",""]#["abcd", "dcba", "lls", "s", "sssll"]#["bat", "tab", "cat"]
obj = Solution()
print(obj.palindromePairs(words))