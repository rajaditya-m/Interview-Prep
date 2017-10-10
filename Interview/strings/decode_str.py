# def decodeStrings(st):
#     n = len(st)
#     tab = [0]*n
#     if st[0]!='0':
#         tab[0] = 1
#     for i in range(1,n):
#         if i-1>=0 and st[i]!='0':
#             tab[i] = tab[i-1]
#         if i-2>=0 and int(st[i-1:i+1])>0 and int(st[i-1:i+1])<=26:
#             tab[i] += tab[i-2]
#         if tab[i]==0:
#             return 0
#     print(tab   )
#     return tab[n-1]

def decodeStrings(st):
    n = len(st)
    tab = [0]*n
    if st[0]!='0':
        tab[0] = 1
    for i in range(1,n):
        if i-1>=0 and st[i]!='0':
            tab[i] = tab[i-1]
        if i-2>=0:
            if int(st[i-1:i+1])>0 and int(st[i-1:i+1])<=26:
                tab[i] += tab[i-2]
        else:
            if int(st[i-1:i+1])>0 and int(st[i-1:i+1])<=26:
                tab[i] += 1
        if tab[i]==0:
            return 0
    print(tab   )
    return tab[n-1]

s1 = '21234'
print(decodeStrings(s1))