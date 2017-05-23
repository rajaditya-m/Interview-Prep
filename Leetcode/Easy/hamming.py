def hamming(x,y):
    #first xor the two to find the indifferent bits
    xor_res = x^y
    #next count the number of bits in the xor
    count = 0
    while xor_res:
        xor_res = xor_res & (xor_res-1)
        count += 1
    return count


x = 1
y = 4
print(hamming(x,y))