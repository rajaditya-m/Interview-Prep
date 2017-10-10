class Solution:
    def maximumSwap(self,num):
        hashtable = {}
        str_rep = str(num)
        n = len(str_rep)
        for idx,c in enumerate(str_rep):
            if not c in hashtable:
                hashtable[c] = [idx]
            else:
                hashtable[c].append(idx)
        # print(hashtable)
        i1, i2 = -1, -1
        for idx, c in enumerate(str_rep):
            digit = int(c)
            for i in range(9,digit,-1):
                # print(c,i)
                if str(i) in hashtable:
                    idx_table = hashtable[str(i)]
                    print(c,  i, idx_table)
                    for j in idx_table:
                        if j>idx:
                            i1 = idx
                            i2 = j
                            break
                    if i1 != -1:
                        break
            if i1 != -1:
                break
        ans = ''
        # print(i1,i2)
        for idx, c in enumerate(str_rep):
            if idx == i1:
                ans += str_rep[i2]
            elif idx == i2:
                ans += str_rep[i1]
            else:
                ans += c
        return int(ans)

                         
        
obj = Solution()
n = 98368
print(obj.maximumSwap(n))