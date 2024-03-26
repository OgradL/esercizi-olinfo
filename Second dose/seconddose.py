#!/usr/bin/env python3

# input data
N1, N2 = list(map(int, input().strip().split()))
ID1 = list(map(int, input().strip().split()))
ID2 = list(map(int, input().strip().split()))


c = list(set(ID1) & set(ID2))

leng = len(c)
print(leng)  # print the result
