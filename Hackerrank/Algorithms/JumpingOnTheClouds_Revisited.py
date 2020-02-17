#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c, k):
    i =0
    n = len(c)
    if c[0] == 1:
        e = 98
    else:
        e = 100
    while((i+k)%n != 0):
        print(c[(i+k)%n],e)
        # print((i+k)%n)
        if(c[(i+k)%n] ==1):
            e -= 3
        else:
            e -= 1
        i +=k
    return e-1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c, k)

    fptr.write(str(result) + '\n')

    fptr.close()
