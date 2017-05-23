def arrayPairSum(nums):
    nums.sort(reverse=True)
    x = sum([i for idx,i in enumerate(nums) if idx%2==1 ])
    return x

n = [1, 4, 3, 2]
print(arrayPairSum(n))