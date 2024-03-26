#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
A = [None] * N
B = [None] * N
for i in range(N):
    A[i], B[i] = map(int, input().strip().split())

stop = False
min = 0
for i in range(N - 1):
    if not (A[i] <= B[i + 1] and B[i] >= A[i + 1]):
        stop = True
        break




if stop:
    print("NO")
else:
    print("YES")