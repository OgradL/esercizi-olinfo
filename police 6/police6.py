#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N, M, L = map(int, input().strip().split())
D = list(map(int, input().strip().split()))

places = [0]*L
for d in D:
    for v in range(max(d-M,0), min(d+M, L)):
        places[v] += 1
        
print(min(places))  # print the result
