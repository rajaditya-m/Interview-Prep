import copy

class Solution:
    def CWHelper(self, arr, runningTotal, target, curPlayer):
        for idx,num in enumerate(arr):
            simScore = runningTotal + num
            if simScore >= target:
                if curPlayer==0:
                    print(arr)
                    return True
                else:
                    return False
            else:
                newArr = copy.deepcopy(arr)
                del newArr[idx]
                nextPlayer = 0 if curPlayer==1 else 1
                dfsResult = self.CWHelper(newArr, simScore, target, nextPlayer)
                if dfsResult:
                    return True
        return False

    def CW(self, limit, maxScore):
        arr = list(range(1, limit+1))
        runningTotal = 0
        return self.CWHelper(arr, runningTotal, maxScore, 0)

obj = Solution()
print(obj.CW(10, 11))