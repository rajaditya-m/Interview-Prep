'''
639. Decode Ways II My SubmissionsBack to Contest
User Accepted: 74
User Tried: 218
Total Accepted: 75
Total Submissions: 620
Difficulty: Hard
A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
Note:
The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
'''
class Solution:
    def numDecodings_SLOW(self, s):
        """
        :type s: str
        :rtype: int
        """
        largeNum = 1000000007
        if not s:
            return 0
        n = len(s)
        dp_table = [0]*n
        if s[0]=='0':
            dp_table[0] = 0
        elif s[0]=='*':
            dp_table[0] = 9
        else:
            dp_table[0] = 1
        for k in range(1, n):
            cur = s[k]
            cur_start = None
            cur_end = None
            if cur != '*':
                cur_start = cur_end = int(cur)
            else:
                cur_start = 1
                cur_end = 2
            prev = s[k-1]
            prev_start = None
            prev_end = None
            if prev != '*':
                prev_start = prev_end = int(prev)
            else:
                prev_start = 1
                prev_end = 9
            for prev in range(prev_start, prev_end+1):
                for cur in range(cur_start, cur_end+1):
                    last_two = 10*prev + cur
                    #print(cur, last_two)
                    if last_two>9 and last_two<=26:
                        if k>=2:
                            dp_table[k] = (dp_table[k] + dp_table[k-2])%largeNum
                        else:
                            dp_table[k] = (dp_table[k] + 1)%largeNum
            if cur_start:
                for cur in range(cur_start, cur_end+1):
                    dp_table[k] = (dp_table[k] + dp_table[k-1])%largeNum
        return dp_table[n-1]

    def numDecodings_SLOW(self, s):
        """
        :type s: str
        :rtype: int
        """
        largeNum = 1000000007
        if not s:
            return 0
        n = len(s)
        dp_table = [0]*n
        if s[0]=='0':
            dp_table[0] = 0
        elif s[0]=='*':
            dp_table[0] = 9
        else:
            dp_table[0] = 1
        for k in range(1, n):
            cur = s[k]
            cur_start = None
            cur_end = None
            if cur != '*':
                cur_start = cur_end = int(cur)
            else:
                cur_start = 1
                cur_end = 2
            prev = s[k-1]
            prev_start = None
            prev_end = None
            if prev != '*':
                prev_start = prev_end = int(prev)
            else:
                prev_start = 1
                prev_end = 9
            for prev in range(prev_start, prev_end+1):
                for cur in range(cur_start, cur_end+1):
                    last_two = 10*prev + cur
                    #print(cur, last_two)
                    if last_two>9 and last_two<=26:
                        if k>=2:
                            dp_table[k] = (dp_table[k] + dp_table[k-2])%largeNum
                        else:
                            dp_table[k] = (dp_table[k] + 1)%largeNum
            if cur_start:
                for cur in range(cur_start, cur_end+1):
                    dp_table[k] = (dp_table[k] + dp_table[k-1])%largeNum
        return dp_table[n-1]

obj = Solution()
str = '*********'
print(obj.numDecodings(str))