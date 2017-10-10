class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        i = 0
        j = n-1
        while i<n and i<=j and s[i]==s[j]:
            i += 1
            j -= 1
        # print(i,j)
        if i>j:
            return True
        saved_i = i
        saved_j = j
        i += 1
        # print(i,j)
        while i<n and i<=j and s[i]==s[j]:
            i += 1
            j -= 1
        if i>j:
            return True
        i = saved_i
        j = saved_j
        j -= 1
        while i<n and i<=j and s[i]==s[j]:
            i += 1
            j -= 1
        if i>j:
            return True
        return False