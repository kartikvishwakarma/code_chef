#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the connectedCell function below.
#def connectedCell(matrix):
def connectedCell(matrix):
    # Complete this function
    result_list = []
    n,m = len(matrix),len(matrix[0])
    for i in range(0,n):
        for j in range(0,m):
            if matrix[i][j] == 1:
                result_list.append(dfs(matrix,i,j))
    return max(result_list)
                
def dfs(matrix,i,j):
    n,m = len(matrix),len(matrix[0])
    if i < 0 or j < 0 or i >= n or j >= m:
        return 0
    if matrix[i][j] == 0:
        return 0
    if matrix[i][j] == 1:
        matrix[i][j] = 0
        return 1+dfs(matrix,i-1,j)+dfs(matrix,i+1,j)+dfs(matrix,i,j-1)+dfs(matrix,i,j+1) 

#if __name__ == '__main__':
#    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    
   
    n = int(input())

    m = int(input())

  # n,m = map(int,sys.stdin.readline().split())

    matrix = []

    for _ in range(n):
        matrix.append(list(map(int, input().rstrip().split())))

    result = connectedCell(matrix)

    print(result)
    fptr.write(str(result) + '\n')

    fptr.close()