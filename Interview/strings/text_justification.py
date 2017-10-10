def textJustification(words, l):
    map_cntr = {}
    word_assignment_list = []
    rem = l
    line_counter = 0
    for word in words:
        n = len(word)
        if n<rem:
            rem -= n
            rem -= 1
        elif n==rem:
            rem -= n #last line
        else:
            line_counter += 1
            rem = l-n
            rem -= 1
        if not line_counter in map_cntr:
            map_cntr[line_counter] = []
        map_cntr[line_counter].append(n)
    print(map_cntr)
    ans = []
    w_counter = 0
    for lc in range(line_counter+1):
        len_sum = sum(map_cntr[lc])
        n_words = len(map_cntr[lc])
        if n_words !=1:
            n_spaces = (l-len_sum) // (n_words-1)
            extra_spaces = (l-len_sum) % (n_words-1)
        print(n_spaces)
        print(extra_spaces)
        if n_spaces<1:
            return #error case
        line = ''   
        ex_s_c = 0 
        if lc != line_counter:
            for i in range(n_words):
                if i!=0:
                    for k in range(n_spaces):
                        line += '#'
                    if ex_s_c<extra_spaces:
                        line +=  '#'
                        ex_s_c += 1
                line += words[w_counter]
                w_counter += 1
        else:
            for i in range(n_words):
                if i!=0:
                    line +=  '#'
                line += words[w_counter]
                w_counter += 1
        if len(line)!=l:
            ll = len(line)
            for i in range(l-ll):
                line += '#'
        ans.append(line)
        print(line)
    return ans





wordl = ["This", 
 "is", 
 "an", 
 "example", 
 "of", 
 "text", 
 "justification."]

# wordl = ["Two", 
#  "words."]

ll = 16 #16

print(textJustification(wordl, ll))