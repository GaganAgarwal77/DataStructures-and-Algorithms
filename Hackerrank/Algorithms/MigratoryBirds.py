#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the migratoryBirds function below.
def migratoryBirds(arr):
    l = []
    for i in range(len(arr)):
        l += [0]
    for i in arr:
        l[i] += 1
    return l.index(max(l))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
