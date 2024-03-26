#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N, M = map(int, input().strip().split())
C = list(map(int, input().strip().split()))

tot = sum(C)


left = M % tot

if left == 0:
    left = tot

#print(left)

for i in range(N):
    left -= C[i]
    if left <= 0:
        print(i)
        break



#print(42)  # print the result
