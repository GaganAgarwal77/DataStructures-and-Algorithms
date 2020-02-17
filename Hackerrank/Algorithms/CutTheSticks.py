#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the cutTheSticks function below.
def CheckArray(arr):
    n = len(arr)
    i = 0 
    for i in range(n):
        if arr[i] != arr[0]:
            break
    if i == n or str(arr) == "[]":
        return True
    else:
        return False
def cutTheSticks(arr):
    # n = len(arr)
    k = CheckArray(arr)
    ans = []         
    while(k == False):
        ans.append(len(arr))
        minim = min(arr)
        # print(minim)
        arr = [ i - minim for i in arr]
        # print(arr)
        l = []
        for i in arr:
            if i != 0:
                l.append(i)
        arr = l
        k = CheckArray(arr)   

    
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = cutTheSticks(arr)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
