import math
n = int(input())
l = [[int(x) for x in input("").split()] for i in range(n)]
pd = []
sd = []
for i in range(n):
    pd.append(l[i][i])
    sd.append(l[i][n-i-1])
print(abs(sum(pd)-sum(sd)))