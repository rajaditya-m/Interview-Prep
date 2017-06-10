class Solution:
    def findNonRep(self, nums):
        bitCntr = [0]*32
        for num in nums:
            for i in range(0, 32):
                bitVal = (num >> i) & 1
                if bitVal:
                    bitCntr[i] += 1
        res = 0
        pow = 1
        for i in range(0, 32):
            if bitCntr[i]%3:
                res += 2**i
        return res

obj = Solution()
nums = [1,1,1,2,2,2,3,3,3,4,4,4,5,5,6,6,6]
print(obj.findNonRep(nums))