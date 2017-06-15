class Solution:
    def UBER_patternMatching(self, str, pat):
        """
        :type str: string
        :type pat: string
        :rtype: bool
        """
        if not pat:
            return not str
        minReps = 1
        maxReps = 1
        closeBraces = 0
        char = pat[0]
        if len(pat) > 1:
            if pat[1] == '{':
                closeBraces = pat.find('}')
                rangeSubstr = pat[2:closeBraces]
                leftStr, rightStr = rangeSubstr.split(',')
                maxReps = int(rightStr)
                minReps = int(leftStr)
                # print(minReps, maxReps)
        cntr = 0
        while cntr < minReps:
            if str[cntr] != char:
                return False
            cntr += 1
        newStr = str[minReps:]
        newPat = pat[closeBraces+1:]
        if maxReps > minReps:
            diff = maxReps - minReps
            for i in range(0, diff):
                newPatDiffed = char*i + newPat
                # print(newPatDiffed, newStr)
                success = self.UBER_patternMatching(newStr, newPatDiffed)
                if success:
                    return True
            return False
        else:
            return self.UBER_patternMatching(newStr, newPat)

obj = Solution()
str = 'abcc'
pat = 'a{1,3}b{1,3}cc{1,3}'
print(obj.UBER_patternMatching(str, pat))


        
