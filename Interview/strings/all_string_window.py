def satisfied(counter, cur_counter):
    for i in range(26):
        if counter[i]:
            if cur_counter[i]<counter[i]:
                return False
    return True

def minSubstringWithAllChars(s, t):
    ws, we = 0,0
    n = len(s)
    char_counter = [0]*26
    for ch in t:
        char_counter[ord(ch)-ord('a')] += 1
    window_counter = [0]*26
    min_len,mws = 9999, -1
    while we<n:
        window_counter[ord(s[we])-ord('a')] += 1 
        while satisfied(char_counter, window_counter):
            w_len = we-ws+1
            if min_len>w_len:
                min_len = w_len
                mws = ws
            window_counter[ord(s[ws])-ord('a')] -= 1
            ws += 1
        we += 1
    return s[mws:mws+min_len]

ss = 'adobecodebanc'
tt = 'abc'

print(minSubstringWithAllChars(ss,tt))