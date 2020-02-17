#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    a = ""
    for i in s[:2]:
        a +=i
    
    
    if s[8:10] == "AM":
        if s[:2] == "12":
            sr =  "00"
        else:
            sr = s[:2] 
    else:
        if s[:2] == "12":
            sr = s[:2]
        else:
            sr =  str(int(a)+12)

    for i in s[2:8]:
        sr += i
    return sr
    #
    # Write your code here.
    #

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
