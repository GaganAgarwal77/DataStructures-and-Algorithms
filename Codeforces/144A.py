n  = input()
a = []
l = [int(x) for x in raw_input().split()]
ans = 0
max = max(l)
min = min(l)
ans += l.index(max)
a = l[::-1]
index = n-1-a.index(min)
if(index < l.index(max)):
    ans += n-1 -index - 1
else:
    ans += n-1 -index

print ans
