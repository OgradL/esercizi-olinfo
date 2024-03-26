#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

# input data
N, D = map(int, input().strip().split())
P = list(map(int, input().strip().split()))


def search(arr, x, lo, hi):
    while lo + 1 < hi:
        
        mid = int((lo + hi) / 2)
        
        if arr[mid] >= x:
            hi = mid
        elif arr[mid] < x:
            lo = mid
    return lo


answer = 0

for i in range(N - 1):
    lo = 0
    hi = N
    x = i
    val = P[i]
    to_find = P[i] + D
    
    found = search(P, to_find, 0, N)
    
    
    #print(found, x)
    #print()
    diff = found - x
    answer += diff




print(answer)  # print the result
