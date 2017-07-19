import copy
import functools

def comparator(a,b):
    ab = int(str(a)+str(b))
    ba = int(str(b)+str(a))
    if ab < ba:
        return -1
    elif ab == ba:
        return 0
    else:
        return 1

class Solution:

    def removeLeadingZeros(self, str):
        leadingZeros = 0
        for char in str:
            if char=='0':
                leadingZeros += 1
            else:
                break
        if leadingZeros==len(str):
            leadingZeros -= 1
        return str[leadingZeros:]


    def largestNumber(self, nums):
        nums.sort(key=functools.cmp_to_key(comparator),reverse=True)
        res = ""
        for n in nums:
            res += str(n)
        return self.removeLeadingZeros(res)

nums = [0,0]
obj = Solution()
print(obj.largestNumber(nums))