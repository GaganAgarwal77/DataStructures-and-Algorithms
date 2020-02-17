#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the birthday function below.
def birthday(s, d, m):
    ans = 0
    count =0
    for j in range(m):
        ans += s[j]
    if(ans == d):
        count +=1
    for i in range(1,len(s)-m+1):
        ans = (ans - s[i-1]) + s[i+m-1]
        if(ans == d): 
            count += 1
    
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = list(map(int, input().rstrip().split()))

    dm = input().rstrip().split()

    d = int(dm[0])

    m = int(dm[1])

    result = birthday(s, d, m)

    fptr.write(str(result) + '\n')

    fptr.close()
