#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    count = 0
    i =0
    while(i <= len(c) -2):
        print(i)
        if(i != n-2 and c[i+2] == 0):
            print("yes")
            i = i+2
        else:
            i = i+1
        count += 1
    print(i)
    return count  
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()
