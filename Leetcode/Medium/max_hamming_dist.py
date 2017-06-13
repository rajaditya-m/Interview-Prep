import random
class Solution:
	def bruteForce(self, nums):
		totalHammingDistance = 0
		for i in range(0, len(nums)):
			for j in range(i+1, len(nums)):
				# print(nums[i],nums[j], self.hammingDistance(nums[i], nums[j]))
				totalHammingDistance += self.hammingDistance(nums[i], nums[j])
		return totalHammingDistance

	def hammingDistance(self, num1, num2):
		xorVal = num1 ^ num2
		hammingDist = 0
		while xorVal:
			hammingDist += 1
			xorVal = xorVal & (xorVal-1)
		return hammingDist

	def totalHammingDistance(self, nums):
			hammingDist = 0
			for i in range(0, 32):
				numZeros = 0
				numOnes = 0
				for num in nums:
					bitVal = (num >> i) & 1
					if bitVal:
						numZeros += 1
					else:
						numOnes += 1
				if numOnes and numZeros:
					hammingDist += numZeros*numOnes
			return hammingDist

obj = Solution()
for j in range(0,20):
	nums = []
	for i in range(0,49):
		nums.append(random.randrange(0,100))
	# nums =  [4,14,2,3]
	groundTruth = obj.bruteForce(nums)
	myVal = obj.totalHammingDistance(nums)
	if groundTruth==myVal:
		print('PASS')
	else:
		print('FAIL')