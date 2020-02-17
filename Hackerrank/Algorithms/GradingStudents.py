#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gradingStudents' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY grades as parameter.
#

def gradingStudents(grades): 
    arr = []
    for grade in grades:
        a = int(grade/10)
        b = grade % 10
        if grade>=38:
            if b==3 or b ==4:
                b = 5
            elif b == 8 or b==9:
                b = 0
                a = a+1
            else:
                b = b
                a = a
        arr+= [10*a +b]
    return arr
    # Write your code here

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grades_count = int(input().strip())

    grades = []

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)

    result = gradingStudents(grades)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
