n = input("")
nums= input("")
nums = nums.split(" ")
list = []
total = 0
for x in nums:
    list.append(int(x))
for num in list:
    total += num
print(total)