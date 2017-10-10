def robbery(amounts):
    n = len(amounts)
    dp_table = [0]*n
    for i in range(n):
        if i-2>=0:
            dp_table[i] = max(dp_table[i],dp_table[i-2]+amounts[i])
        if i-1>=0:
            dp_table[i] = max(dp_table[i],amounts[i],dp_table[i-1])
        else:
            dp_table[i] = max(dp_table[i],amounts[i])
    print(dp_table)
    return dp_table[n-1]

amounts =[40,25,25,30]
robbery(amounts)