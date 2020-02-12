n = input()
l=[]
for i in range(n):
    l += [[int(x) for x in raw_input().split()]]
count =0
for i in range(n):
    for j in range(n):
        if l[i][0] == l[j][1]:
            count +=1
    
print count