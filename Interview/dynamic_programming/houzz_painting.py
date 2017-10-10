def paintHouses(cost):
    n = len(cost)
    mc_0 = [None]*n
    mc_1 = [None]*n
    mc_2 = [None]*n
    #initial house has no restrictions 
    mc_0[0] = cost[0][0]
    mc_1[0] = cost[0][1]
    mc_2[0] = cost[0][2]
    for i in range(1,n):
        mc_0[i] = min(mc_1[i-1],mc_2[i-1]) + cost[i][0]
        mc_1[i] = min(mc_0[i-1],mc_2[i-1]) + cost[i][1]
        mc_2[i] = min(mc_0[i-1],mc_1[i-1]) + cost[i][2]
    return min(mc_0[n-1],mc_1[n-1],mc_2[n-1])

#cost = [[3,6,4], [1,2,8], [2,4,7], [5,10,1], [3,4,3], [6,4,1], [8,7,2], [5,6,1], [6,7,3], [5,10,3]]
cost = [[3,2,1], 
 [1,2,3], 
 [2,1,3], 
 [3,2,1], 
 [1,2,3], 
 [3,1,2]]
print(paintHouses(cost))