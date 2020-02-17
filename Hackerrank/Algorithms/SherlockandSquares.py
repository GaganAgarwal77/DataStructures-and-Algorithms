#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the squares function below.
def binarySearch(arr, l, r, x): 
  
    while l <= r: 
  
        mid = l + (r - l)/2; 

        # Check if x is present at mid 
        if arr[mid] == x: 
            return True 
  
        # If x is greater, ignore left half 
        elif arr[mid] < x: 
            l = mid + 1
  
        # If x is smaller, ignore right half 
        else: 
            r = mid - 1
      
    # If we reach here, then the element was not present 
    return False

def is_integer_num(n):
    if isinstance(n, int):
        return True
    if isinstance(n, float):
        return n.is_integer()
    return False

def squares(a, b):
    # a = 3
    # b = 6/2
    # print(a,b)
    # return a==b
    count = 0
    if(a != b):
        count = int(math.sqrt(b)) - int(math.sqrt(a))
        if math.sqrt(a) == int(math.sqrt(a)):
            count +=1
        if math.sqrt(b) == int(math.sqrt(a)):
            count +=1
    else:
        if math.sqrt(a) == int(math.sqrt(a)):
            count += 1
    # for i in range(a,b+1):
    #     if math.sqrt(i) == int(math.sqrt(i)):
    #         count +=1
        # if(binarySearch(range(int(i/2) +1),0,int(i/2),int(math.sqrt(i)))):
        #     count +=1
    #     for j in range(int(i/2) +1):
    #         if int(j*j) == int(i):
    #             print(j,i)
    #             count += 1

    return count
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        ab = input().split()

        a = int(ab[0])

        b = int(ab[1])

        result = squares(a, b)

        fptr.write(str(result) + '\n')

    fptr.close()
