def findWords(words):
    """
    :type words: List[str]
    :rtype: List[str]
    """
    opt_list = []
    for word in words:
        ws = set()
        word_l = word.lower()
        for c in word_l:
            idx = classifyChar(c)
            ws.add(idx)
        set_len = len(ws)
        if(set_len==1):
            opt_list.append(word)
    return opt_list
    
def classifyChar(c):
    rs1 = {'q','w','e','r','t','y','u','i','o','p'}
    rs2 = {'a','s','d','f','g','h','j','k','l'}
    rs3 = {'z','x','c','v','b','n','m'}
    if c in rs1:
        return 1
    elif c in rs2:
        return 2
    else:
        return 3

wl = ["Hello", "Alaska", "Dad", "Peace"]
print(findWords(wl))