class Solution:
    def palindromePairs(self, words):
        trie = {}
        ans = []
        for idx,rev_word in enumerate(words):
            word = rev_word[::-1]
            cur = trie
            for ch in word:
                if not ch in cur:
                    cur[ch] = {}
                if '@' not in cur:
                    cur['@'] = []
                cur['@'].append(idx)
                cur = cur[ch]
            if '#' not in cur:
                cur['#'] = [] 
            cur['#'].append(idx)
            if '@' not in cur:
                cur['@'] = []
            cur['@'].append(idx)
        # print(trie)
        for idx,word in enumerate(words):
            # print(idx, word)
            #traverse the trie
            cur = trie 
            counter = 0
            for i in range(len(word)):
                if not word[i] in cur:
                    break
                cur = cur[word[i]]
                counter += 1
            #check what happens 
            if counter==len(word): #this means a is exhasuted 
                # candidates = cur['@']
                if '#' in cur: #means wither a is itself a palindrome or there exists a b with the same len as a
                    for cands in cur['#']:
                        if cands !=idx:
                            ans.append((idx,cands))
                        else:
                            #self palindrome check
                            if '#' in trie and word: #empty string
                                ans.append((idx,trie['#'][0]))
                            # print(words[idx],words[cands])
                #case 2 check all the rem b's 
                # print(word, cur['@'])
                for cands in cur['@']:
                    if cands != idx:
                        rem_str = words[cands][::-1][counter:]
                        
                        if rem_str :
                            # print(idx, word,cur['@'],cands, words[cands], rem_str)
                            if rem_str==rem_str[::-1]:
                                ans.append((idx,cands))
                            if rem_str==word:
                                ans.append((cands,idx))
                                # print(words[idx],words[cands])
            else: #this means a is not exhausted but b may be
                if '#' in cur:
                    # print(cur['#'])
                    for cands in cur['#']:
                        if cands != idx:
                            rem_str = word[counter:]
                            if rem_str==rem_str[::-1]:
                                ans.append((idx,cands))
                            if rem_str==word:
                                ans.append((cands,idx))
                                # print(words[idx],words[cands])
            # print(word,counter,cur)
        return ans

        
#["a","b","c","ab","ac","aa"]
#Output:
#[[3,0],[1,3],[4,0],[2,4],[0,5]]
#Expected:
#[[3,0],[1,3],[4,0],[2,4],[5,0],[0,5]]



words = ["aa","a"]#["bat", "tab", "cat"]#["geeks","keeg","abc"]##["abcd", "dcba", "lls", "s", "sssll"]##
obj = Solution()
print(obj.palindromePairs(words))