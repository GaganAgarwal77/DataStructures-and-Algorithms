n = input()
l = [int(x) for x in raw_input().split()]
ans = []
for i in range(n):
    ans += [0]

for i in l:
    ans[i-1] = l.index(i)+1
    
for i in range(n):
    print ans[i],