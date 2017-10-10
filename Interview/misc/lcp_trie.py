def foo(wl):
    trie = {}
    for word in wl:
        cur = trie
        for ch in word:
            if not ch in cur:
                cur[ch] = {}
            cur = cur[ch]
    cur = trie
    lcp = ''
    while len(cur)==1:
        for key,val in cur.items():
            lcp += key
            cur = cur[lcp[-1]]
    return lcp

woo = ['char', 'chor', 'choot', 'chamar']
print(foo(woo))