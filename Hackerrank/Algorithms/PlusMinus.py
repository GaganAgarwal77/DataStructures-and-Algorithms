import math
n = float(input(""))
l = [int(x) for x in input("").split()]
p=0
neg=0
z=0
for i in l:
    if i>0:
        p+=1
    elif i<0:
        neg+=1
    else:
        z+=1

print(round((p/n),6))
print(round((neg/n),6))
print(round((z/n),6))