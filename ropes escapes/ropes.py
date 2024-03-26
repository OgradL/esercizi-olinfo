#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
P = list(map(int, input().strip().split()))
T = list(map(int, input().strip().split()))

maximum = [0] * (max(P) + 1)
total = 0
#find the highest element for each node
for i in range(N):
    total += T[i]
    maximum[P[i]] = max(maximum[P[i]], T[i])

total -= sum(maximum)

print(total)
