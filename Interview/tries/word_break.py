class Solution():
    def wordBreak(self, s, wordDict):
        wordSet = set(wordDict)
        n = len(s)
        dp_table = [[False]*n for _ in range(n)]
        for i in range(n):
            for j in range(i,n):
                substr = s[i:j+1]
                if substr in wordSet:
                    dp_table[i][j] = True
        # print(dp_table)
        for i in range(n):
            for j in range(i,n):
                    for k in range(i,j):
                        if not dp_table[i][j]:
                            dp_table[i][j] = dp_table[i][k] & dp_table[k+1][j]
        return dp_table[0][n-1]

    def wordBreak2(self, s, wordDict):
        wordSet = set(wordDict)
        n = len(s)
        dp_table = [[False]*n for _ in range(n)]
        for l in range(1,n+1):
            for i in range(0,n-l+1):
                j = i+l-1
                print(i,j,s[i:j+1])
                if s[i:j+1] in wordSet:
                    dp_table[i][j] = True
                for k in range(i,j):
                    # print(i,k,k+1,j,dp_table[i][k],dp_table[k+1][j] )
                    if dp_table[i][k] and dp_table[k+1][j]:
                                dp_table[i][j] = dp_table[i][k] & dp_table[k+1][j]
        print(dp_table)
        return dp_table[0][n-1]

    def wordBreak3(self, s, wordDict):
        wordSet = set(wordDict)
        return self.helper1(s,wordSet, {})

    def helper1(self, s, wordSet, memo):
        if s in memo:
            return memo[s]
        if not s:
            return [0,[]]
        ans = 0
        list_str = []
        for word in wordSet:
            if s.startswith(word):
                if len(s)==len(word):
                    ans += 1
                    list_str.append([word])
                else:
                    rem_word = s[len(word):]
                    rec_res,rec_list_str = self.helper1(rem_word, wordSet, memo)
                    print(rem_word, rec_res, rec_list_str)
                    if rec_res>0:
                        ans += rec_res
                        for elem in rec_list_str:
                            nelem = [word]
                            nelem.extend(elem)
                            list_str.append(nelem)

        memo[s] = [ans,list_str]
        return [ans,list_str]
 


wordDict = ["cat", "cats", "and", "sand", "dog"]
s = 'catsanddog'

# wordDict = ["ab", "c"]
# s = 'abc'

def foo(a,b,c):
    d = a+b+c
    return d

print(foo.__dict__)

obj = Solution()
print(obj.wordBreak3(s, wordDict))