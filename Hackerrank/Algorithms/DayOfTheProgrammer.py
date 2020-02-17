#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the dayOfProgrammer function below.
def isLeapyear(year):
    if(year%4 ==0 and year%100 !=0):
        return True
    elif(year%400 ==0):
        return True
    else:
        return False
def dayOfProgrammer(year):
    ans =""
    if(year > 1918):
        if(isLeapyear(year)):
            ans = "12.09."+ str(year)
        else:
            ans = "13.09." +str(year) 
    elif(year < 1918):
        if(year%4 ==0):
            ans = "12.09."+ str(year)
        else:
            ans = "13.09." +str(year)
    else:
        if(year%4 ==0):
            ans = "25.09."+ str(year)
        else:
            ans = "26.09."+ str(year)
    
    return ans 
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    year = int(input().strip())

    result = dayOfProgrammer(year)

    fptr.write(result + '\n')

    fptr.close()
