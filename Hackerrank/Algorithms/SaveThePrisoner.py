#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the saveThePrisoner function below.
def saveThePrisoner(n, m, s):
    # l = str(s)
    # for i in range(s+1,n+1):
    #     l += str(i) 
    # for i in range(1,s):
    #     l += str(i)
    # print(l)
    # print(m%n)
    # if(m%n == 0):
    #     a = 0
    # else:
    #     a = m%n -1
    # a = (m-1)%n
    # if ((s+a)%n == 0):
    #     return s
    # else:
    #     return (s+a -)%n
    m = m%n    
    return ((m +s - 2)%n + 1)
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nms = input().split()

        n = int(nms[0])

        m = int(nms[1])

        s = int(nms[2])

        result = saveThePrisoner(n, m, s)

        fptr.write(str(result) + '\n')

    fptr.close()
