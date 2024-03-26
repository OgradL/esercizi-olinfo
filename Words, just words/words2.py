#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import math

MOD = 1000000007


def spliit(word):
    return [char for char in word]

# input data
W = input().strip()

#print(spliit(W))
#W = W[:]
#print(W)
#W = spliit(W)
N = len(W)

#for x in range(N):
#    W[x] = ord(W[x]) - 96 #to get letter number from 1 to 26
    
#pos = pow(26, N - 1)
pos = 0
pos1 = 0

#for i in range(N):
#    pos += pow(26, N - i - 1)

potenza = 1


for i in range(N):
    #print(i, N - i - 1, W[N-i-1:N-i])
    pos += (int(ord(W[N-i-1:N-i]) - 96)) * potenza
    potenza *= 26
    pos %= 1000000007
    #pos1 += W[i] * pow(26, N - i - 1)
    #pos1 %= 1000000007
    
    


#print(W)
print(int((pos - 1) % MOD))
#print(int((pos1 - 1) % MOD))
