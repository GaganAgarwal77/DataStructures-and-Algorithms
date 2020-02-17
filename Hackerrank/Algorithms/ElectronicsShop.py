#!/bin/python3

import os
import sys

#
# Complete the getMoneySpent function below.
#
def getMoneySpent(keyboards, drives, b):
    #min = b%(keyboards[0] + drives[0])
    max = -1
    for i in keyboards:
        for j in drives:
            if(i + j <= b and i+j> max):
                max = i+j
    if max >b:
        return -1
    return max
    #         if(b%(i + j) < min):
    #             min = (i+j)%b 
    #             ans = i+j
    # if b%ans == b:
    #     return -1
    # return ans
    #
    # Write your code here.
    #

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    bnm = input().split()

    b = int(bnm[0])

    n = int(bnm[1])

    m = int(bnm[2])

    keyboards = list(map(int, input().rstrip().split()))

    drives = list(map(int, input().rstrip().split()))

    #
    # The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    #

    moneySpent = getMoneySpent(keyboards, drives, b)

    fptr.write(str(moneySpent) + '\n')

    fptr.close()
