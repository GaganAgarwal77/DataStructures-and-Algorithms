a = input().split()
b = input().split()
for i in range(3):
    a[i] =int(a[i])
    b[i] =int(b[i])
c = [0,0]
for i in range(3):
    if a[i] > b[i]:
        c[0] = c[0] + 1
    elif a[i] < b[i]:
        c[1] = c[1] + 1
    
        continue
    
for num in c:
    print(num,end=" ")