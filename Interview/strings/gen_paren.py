def generateParenthesis(n):
    """
    :type n: int
    :rtype: List[str]
    """
    total_list = []
    total_list.append([''])
    for i in range(1,n+1):
        new_range = []
        for alpha in range(0,i):
            beta = i-1-alpha
            alpha_parens = total_list[alpha]
            beta_parens = total_list[beta]
            for ap in alpha_parens:
                for bp in beta_parens:
                    parens = '({}){}'.format(ap,bp)
                    new_range.append(parens)
        total_list.append(new_range)
    print(total_list)

generateParenthesis(3)