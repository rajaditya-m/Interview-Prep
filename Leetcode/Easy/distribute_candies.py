def distributeCandies(candies):
    n2 = len(candies)
    n = int(n2/2)
    #first form the valid dictionary 
    distribution_dict = {}
    for i in candies:
        distribution_dict[i] = distribution_dict.get(i,0) + 1
    n_candy_types = len(distribution_dict)
    if(n_candy_types>=n):
        return n
    else:
        return n_candy_types


cd = [1,1,1,1,2,2,2,3,3,3]

print(distributeCandies(cd))
        