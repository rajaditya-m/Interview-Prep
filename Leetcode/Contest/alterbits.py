class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n<2:
            return False
        c = n
        counter = 0
        last_set = -1
        while c:
            if c & 1:
                if last_set==-1:
                    if counter>=2:
                        return False
                    else:
                        last_set = counter
                else:
                    if counter-last_set!=2:
                        return False
                    else:
                        last_set = counter
            c = c >> 1
            counter += 1
        return True

obj = Solution()
for i in range(100):
    print(bin(i),obj.hasAlternatingBits(i))