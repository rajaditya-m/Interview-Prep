class Solution:
    def replaceWords(self, dict, sentence):
        #construct the trie 
        trie = {}
        for word in dict:
            cur = trie
            for char in word:
                if char not in cur:
                    cur[char] = {}
                cur = cur[char]
            if '#' not in cur:
                cur['#'] = ''
        # print(trie)
        #now we will search the trie 
        newSentence = ''
        for idx, word in enumerate(sentence.split(' ')):
            #Lets search the trie
            cur = trie
            trail = ''
            newWord = word
            for char in word:
                    #remember the smallest clause
                    #check if '#' occurs as a terminating character
                if '#' in cur:
                    # that means we have found some stuff
                    newWord = trail
                    break
                if char in cur:
                    cur = cur[char]
                    trail += char
                else:
                    break
            newSentence += newWord
            newSentence += ' '
        return newSentence.strip()


obj = Solution()
wordlist = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
wordlist = ["a", "aa", "aaa", "aaaa"]
sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
print(obj.replaceWords(wordlist, sentence))
