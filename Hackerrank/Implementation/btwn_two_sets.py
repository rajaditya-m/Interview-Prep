#assume that there are two numbers and two sets with those numbers

def allFactorsAreElements(vec, num):
    for e in vec:
        if e%num:
            return False
    return True

def allElementsAreFactors(vec, num):
    for e in vec:
        if num%e:
            #print('e'+str(e))
            return False
    return True

n = 2
m = 3

a = [2,4]
b = [16,32,96]

a.sort()
b.sort()
lowerLims = a[n-1]
upperLims = b[0]

counter = 0
for i in range(lowerLims,upperLims+1):
    if(allFactorsAreElements(b,i) and allElementsAreFactors(a,i)):
        counter += 1

print(counter)