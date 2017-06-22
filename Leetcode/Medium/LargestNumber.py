import copy

def comparator(self, a,b):
    ab = int(str(a)+str(b))
    ba = int(str(b)+str(a))
    if ab < ba:
        return -1
    elif ab == ba:
        return 0
    else:
        return 1

class Solution:
    def largestNumber_WRONG(self, nums):
        for i in range(1, 20):
            noHits = True
            countingSort = [[] for j in range(0, 10)]
            modifiedIdx = set()
            for idx, n in enumerate(nums):
                strVal = str(n)
                digitStr = None
                if i <= len(strVal):
                    digitStr = strVal[-i]
                if digitStr:
                    digit = int(digitStr)
                    countingSort[digit].append(idx)
                    modifiedIdx.add(idx)
                    noHits = False
            if noHits:
                break
            ordering = []
            for j in range(9, -1, -1):
                for k in countingSort[j]:
                    ordering.append(k)
            buffer,c = [],0
            for j in range(0, len(nums)):
                if j in modifiedIdx:
                    buffer.append(nums[ordering[c]])
                    c += 1
                else:
                    buffer.append(nums[j])
            nums = copy.deepcopy(buffer)
        result = ""
        for num in nums:
            result += str(num)
        return result



    def largestNumber(self, nums):
        nums.sort(comparator)
        print(nums)

nums = [20, 1]
obj = Solution()
print(obj.largestNumber(nums))