#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the circularArrayRotation function below.
def circularArrayRotation(a, k, queries):
    l = []
    n = len(a)
    q = len(queries)
    for i in range(n):
        l += [0]
    for i in range(n):
        l[(i+k)%n] = a[i]
    
    count = 0
    arr = []
    for i in range(q):
        arr += [0]
    
    for i in queries:
        arr[count] +=  l[i]
        count += 1
    
    return arr
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nkq = input().split()

    n = int(nkq[0])

    k = int(nkq[1])

    q = int(nkq[2])

    a = list(map(int, input().rstrip().split()))

    queries = []

    for _ in range(q):
        queries_item = int(input())
        queries.append(queries_item)

    result = circularArrayRotation(a, k, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
