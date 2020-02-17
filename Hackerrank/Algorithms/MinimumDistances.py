#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumDistances function below.
def minimumDistances(a):
    l = []
    [l.append(1000000) for i in range(100001)]
    n = len(a)
    print(l)
    for i in range(n):
        if(l[a[i]] == 1000000):
            l[a[i]] = 10000000
        else:
            l[a[i]] = abs(a.index(a[i]) - i)
    print(l)
    if(min(l) == 1000000):
        return -1
    else:
        return min(l) 

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    a = list(map(int, input().rstrip().split()))

    result = minimumDistances(a)

    fptr.write(str(result) + '\n')

    fptr.close()
