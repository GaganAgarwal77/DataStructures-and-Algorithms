l = []
for i in range(5):
    l += [[int(x) for x in raw_input().split()]]
column_number = 0
row_number = 0
for i in l:
    for j in i:
        if j == 1:
            column_number = l.index(i)
            a = l[l.index(i)]
            row_number = a.index(j)


ans = abs(column_number - 2) + abs(row_number - 2)

print ans