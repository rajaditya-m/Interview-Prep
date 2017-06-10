class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        str = ''
        num = 0
        stack = []
        for char in s:
            if char == '[':
                stack.append([str,num])
                str = ''
                num = 0
            elif char.isdigit():
                digit = ord(char)-ord('0')
                num = num*10 + digit 
            elif char == ']':
                prevStr, n = stack.pop()
                str = prevStr + str * n
            else:
                str += char
        return str

s = '3[a2[c]]'
obj = Solution()
print(obj.decodeString(s))

