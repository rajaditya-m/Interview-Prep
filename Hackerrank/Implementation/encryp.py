import sys
import math

def encryp(s):
    n = len(s)
    nc = math.ceil(math.sqrt(n))
    nr = math.ceil(n/nc)
    print(nr,nc)
    word_list = ['']*nc
    for c in range(0,nc):
        for r in range(0,nr):
            #compute the row major idx 
            idx = r*nc + c
            if(idx<n):
                word_list[c] += s[idx]
    concat_res = ' '.join(word_list)
    print(concat_res)




s = 'haveaniceday'
encryp(s)

s2 = 'ifmanwasmeanttostayonthegroundgodwouldhavegivenusroots'
encryp(s2)

s3 = 'chillout'
encryp(s3)

s4 = 'feedthedog'
encryp(s4)