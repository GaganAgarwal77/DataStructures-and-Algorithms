#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    count =0
    a = len(s)
    for i in s:
        if i == 'a':
            count +=1
    ans = count*int(n/a)
    print(ans)
    # k = (n%a - 2)%n + 1
    k = n%a
    for i in range(int(k)):
        print(i)
        if(s[i] == 'a'):
            ans += 1
    return ans 


    return ans
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
