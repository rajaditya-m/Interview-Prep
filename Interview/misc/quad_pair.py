def quadruple_sum(integer_list, target_number):
    n = len(integer_list)
    res_set = set()
    for i in range(0,n-3):
        for j in range(i+1,n-2):
            adj_target = target_number - integer_list[i] - integer_list[j]
            k = j+1
            l = n-1
            while k<l:
                print(i,j,k,l)
                if adj_target==integer_list[k]+integer_list[l]:
                    res_set.add((integer_list[i],integer_list[j],integer_list[k],integer_list[l]))
                    k += 1 
                    l -= 1
                elif adj_target>integer_list[k]+integer_list[l]:
                    k +=1
                else:
                    l -= 1
    return list(res_set)

target = 10
il = [1,2,3,4,5,6,7,8]

print(quadruple_sum(il, target))