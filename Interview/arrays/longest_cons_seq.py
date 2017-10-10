class Solution():
    def longestConsecutive(self, nums):
        nums = set(nums)
        long_seq = 0
        for n in nums:
            if not n-1 in nums:
                y = n+1
                while y in nums:
                    y+= 1
                long_seq = max(long_seq,y-n)
        return long_seq

obj = Solution()
x = [100, 4, 200, 1, 3, 2]
print(obj.longestConsecutive(x))
            