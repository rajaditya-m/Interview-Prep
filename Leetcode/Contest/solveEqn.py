class Solution:
    def simplify(self, expr):
        const_stack = []
        var_stack = []
        symbol = '+'
        number = ''
        for c in expr:
            if c=='x':
                if number!='':
                    var_stack.append((symbol, int(number)))
                else:
                    var_stack.append((symbol, 1))
                number = ''
            elif c=='+':
                if number != '':
                    const_stack.append((symbol, int(number)))
                    number = ''
                symbol = '+'
            elif c=='-':
                if number != '':
                    const_stack.append((symbol, int(number)))
                    number = ''
                symbol = '-'
            else:
                number += c
        if number!='':
            const_stack.append((symbol, int(number)))
        #print(const_stack)
        #print(var_stack)
        var_val = self.processStack(var_stack)
        con_val = self.processStack(const_stack)
        #print('{}x+{}'.format(var_val, con_val))
        return [var_val, con_val]

    def processStack(self, stack):
        accumulator = 0
        for item in stack:
            if item[0]=='+':
                accumulator += item[1]
            else:
                accumulator -= item[1]
        return accumulator
    def solveEquation(self, equation):
        equal_idx = equation.find('=')
        left = equation[:equal_idx]
        right = equation[equal_idx+1:]
        #print(left, right)
        vl, cl = self.simplify(left)
        vr, cr = self.simplify(right)
        v = vl-vr
        c = cr-cl
        if v==0:
            if c==0:
                return "Infinite Solution"
            else:
                return "No Solution"
        else:
            return "x={}".format(int(c/v))


exprs = ["x+5-3+x=6+x-2", "x=x", "2x=x", "2x+3x-6x=x+2", "x=x+2"]
obj = Solution()
for e in exprs:
    print(obj.solveEquation(e))