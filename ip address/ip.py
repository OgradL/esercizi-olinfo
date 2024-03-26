#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
A = list(map(int, input().split(".")))
B = list(map(int, input().split("."))) 

C = []

for i in range(4):
    C.append(B[i] - A[i])

total = 1
total += C[0] * 256 * 256 * 256 + C[1] * 256 * 256 + C[2] * 256 + C[3]

#print(C)


print(total)  # print the result