class Solution:
    def findMaxForm_WRONG(self, strs, m, n):
        if not strs:
            return None
        nos = len(strs)
        dp_table = [0]*nos
        num_zeros = [0]*nos
        num_ones = [0]*nos
        max_val = 0
        for i in range(0, nos):
            n_0, n_1 = self.analyze(strs[i])
            if n_0<=m and n_1<=n:
                dp_table[i] = 1
                num_zeros[i] = n_0
                num_ones[i] = n_1
            for j in range(0, i):
                if (n_0 + num_zeros[j] <= m) and (n_1 + num_ones[j] <= n):
                    # print(i,j)
                    if dp_table[j]+1 > dp_table[i]:
                        dp_table[i] = dp_table[j] + 1
                        num_zeros[i] = n_0 + num_zeros[j]
                        num_ones[i] = n_1 + num_ones[j]
            max_val = max(max_val, dp_table[i])
            # print(dp_table)
            # print(num_ones)
            # print(num_zeros)
            # print('/////')
        return max(dp_table)

    def findMaxForm(self, strs, m, n):
        nos = len(strs)
        #dp_table = [[[0]*(nos+1) for i in range(0,m)] for j in range(0,n)]
        dp_table = [[[0]*(n+1) for i in range(0,m+1)] for j in range(0,nos+1)]
        for i in range(0, nos+1):
            if i!=0:
                n_0, n_1 = self.analyze(strs[i-1])
            for j in range(0, m+1):
                for k in range(0, n+1):
                    if i==0:
                        dp_table[i][j][k] = 0
                    else:
                        if n_0 > j or n_1 > k:
                            print('****')
                            print(n_0, n_1)
                            print(i,j,k)
                            print('****')
                            dp_table[i][j][k] = 0
                        else:
                            print('....')
                            print(n_0, n_1)
                            print(i,j,k)
                            print(i-1,j,k)
                            print(i-1,j-n_0,k-n_1)
                            print('....')
                            dp_table[i][j][k] = max(dp_table[i-1][j][k], dp_table[i-1][j-n_0][k-n_1] + 1)
        print(dp_table[nos])
        

    def analyze(self, st):
        n_0 = 0
        n_1 = 0
        for ch in st:
            if ch=='0':
                n_0 += 1
            else:
                n_1 += 1
        return [n_0, n_1]


obj = Solution()
strs = ["10", "0001", "111001", "1", "0"]
#strs = ["10", "0", "1"]
m = 5
n = 3
print(obj.findMaxForm(strs, m, n))
