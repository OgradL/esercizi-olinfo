#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.
"""
from __future__ import print_function
try: input = raw_input
except: pass

import sys 
sys.stdout = open("output.txt", "w")
sys.stdin = open("input.txt", "r")
"""

import re

# input data
N = int(input().strip())

count = N 

for i in range(N):
    S = str(input().strip())
    
    
    S = S.lower()
    #S = S.replace(" ", "")
    #S = S.replace(".", "")
    #print(S)
    #print(ord(".") - 97)
    for k in S:
        if ord(k) - 97 >= 26 or ord(k) - 97 < 0:
            #print(k)
            continue
        #print(re.findall(k, S))
        if len(re.findall(k, S)) > 2:
            count -= 1
            break

    
print(count)  # print the result
