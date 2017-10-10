def get_hash_value(s):
    #length is constant 10
    lookup_table = {'A':0, 'C':1, 'G':2, 'T':3}
    multiplier = 1
    ans = 0
    for i in range(9,-1,-1):
        val = lookup_table[s[i]]
        ans += multiplier*val
        multiplier *= 4
    return ans

def get_rolling_hash(old_hash, new_char, prec_car):
    lookup_table = {'A':0, 'C':1, 'G':2, 'T':3}
    val = old_hash - ((4**9)*lookup_table[prec_car])
    val *= 4
    val += lookup_table[new_char]
    return val


def repeatedDNASequences(s):
    n = len(s)
    if n<10:
        return []
    ans = []
    hashtable = {}
    s0 = s[0:10]
    h0 = get_hash_value(s0)
    if not h0 in hashtable:
        hashtable[h0] = []
    hashtable[h0].append(0)
    # print(s0,h0)
    # for i in range(1,n-10+1):
    #     s1 = s[i:i+10]
    #     print(s1, get_hash_value(s1))
    # print('-------')
    # print(s0,h0)
    for i in range(10,n):
        nc = s[i]
        pc = s[i-10]
        h1 = get_rolling_hash(h0,nc,pc)
        if not h1 in hashtable:
            hashtable[h1] = []
        hashtable[h1].append(i-9)
        # s1 = s0[1:10]+nc
        # print(s0[1:10]+nc,h1)
        h0 = h1
        # s0 = s1
    cand_table = []
    for key,value in hashtable.items():
        if len(value)>1:
            cand_table.append((key,value[0]))
            # ans.append(s[value[0]:value[0]+10])
    print(cand_table)
    cand_table.sort()
    for cand in cand_table:
        ans.append(s[cand[1]:cand[1]+10])
    return ans
    


ss = 'AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT'
ss = 'GAGAGAGAGAGAG'
print(repeatedDNASequences(ss))
    