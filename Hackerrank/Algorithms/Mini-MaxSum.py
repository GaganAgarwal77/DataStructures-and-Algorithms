def miniMaxSum(arr):
    arr.sort()
    min_sum = 0
    max_sum = 0
    for i in range(4):
        min_sum += arr[i]
    for i in range(1,5):
        max_sum += arr[i]
    print(min_sum , max_sum)
    
if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))
    miniMaxSum(arr)