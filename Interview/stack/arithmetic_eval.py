class Solution(object):
    def precedence(self, op):
        if op=='+' or op=='-':
            return 1
        else:
            return 2    

    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        op_stack = []
        num_list = []
        n = ''
        for c in s:
            if c=='+' or c=='-' or c=='*' or c=='/':
                if n!='':
                    num_list.append(int(n))
                    n = ''
                if not op_stack:
                    op_stack.append(c)
                else:
                    while op_stack and self.precedence(c)<=self.precedence(op_stack[-1]):
                        num_list.append(op_stack.pop())
                    op_stack.append(c)
            elif c.isdigit():
                n += c
        if n!='':
            num_list.append(int(n))
        while op_stack:
            num_list.append(op_stack.pop())
        
        return self.postfixeval(num_list)

    def postfixeval(self, postfix):
        val_stack = []
        for elem in postfix:
            if isinstance(elem, int):
                val_stack.append(elem)
            else:
                op2 = val_stack.pop()
                op1 = val_stack.pop()
                res = None
                if elem=='+':
                    res = op1 + op2
                elif elem=='-':
                    res = op1 - op2
                elif elem=='*':
                    res = op1 * op2
                else:
                    res = op1 // op2
                val_stack.append(res)
        return val_stack[0]



        



obj = Solution()
exp = '25/6+ 3'
print(obj.calculate(exp))