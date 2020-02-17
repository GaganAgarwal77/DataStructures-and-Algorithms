#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    counter = 0
    ans = 0
    for i in range(n):
        #print(counter,ans)
        if(counter == 0 and  s[i] == 'D'):
            ans += 1
        if s[i] == 'U':
            counter += 1
        elif s[i] == 'D':
            counter -= 1

    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
