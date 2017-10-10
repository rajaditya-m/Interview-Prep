import copy

class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return self.helper(s, [],0)

    def helper(self, s, stack, i):
        n = len(s)
        # print(s, stack)
        if n==i:
            if len(stack)==0:
                return True
            else:
                return False
        ch = s[i]
        if ch != '*':
            if ch == '(':
                stack.append('(')
            elif ch == ')':
                if len(stack)==0:
                    return False
                ts = stack.pop()
            return self.helper(s, stack, i+1)
        else:
            saved_stack_1 = copy.copy(stack)
            if len(saved_stack_1)>0:
                saved_stack_1.pop()
                a1 = self.helper(s, saved_stack_1, i+1)
                if a1:
                    return True
            saved_stack_2 = copy.copy(stack)
            saved_stack_2.append('(')
            a2 = self.helper(s, saved_stack_2, i+1)
            if a2:
                return True
            return self.helper(s,stack, i+1)
        
obj = Solution()
print(obj.checkValidString('()'))
print(obj.checkValidString('()()'))
print(obj.checkValidString('(*'))