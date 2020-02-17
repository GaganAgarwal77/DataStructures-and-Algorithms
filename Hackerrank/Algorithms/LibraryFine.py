#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the libraryFine function below.
def checkYear(year): 
    if (year % 4) == 0: 
        if (year % 100) == 0: 
            if (year % 400) == 0: 
                return True
            else: 
                return False
        else: 
             return True
    else: 
        return False

def libraryFine(d1, m1, y1, d2, m2, y2):
    months = [0,31,28,31,30,31,30,31,31,30,31,30,31]
    k = 0
    if(y2 != y1):
        if(y1 > y2):
            return 10000
        elif(y1 < y2):
            return 0
    else:
        if(m1 == m2):
            if(d1<=d2):
                return 0
            else:
                return int(15*(d1-d2))
        else:
            if(m1<m2):
                return 0
            else:
                return int(500*(m1-m2))

# if(checkYear(y1)):
#     months[2] += 1
# k += months[m2] - d2 + 1 + d1
# for i in range(m2+1,m1):
#     k += months[i]
# return int(500*k) 


        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    d1M1Y1 = input().split()

    d1 = int(d1M1Y1[0])

    m1 = int(d1M1Y1[1])

    y1 = int(d1M1Y1[2])

    d2M2Y2 = input().split()

    d2 = int(d2M2Y2[0])

    m2 = int(d2M2Y2[1])

    y2 = int(d2M2Y2[2])

    result = libraryFine(d1, m1, y1, d2, m2, y2)

    fptr.write(str(result) + '\n')

    fptr.close()
