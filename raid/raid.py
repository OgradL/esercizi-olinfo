
import sys
import os
import time
import math

currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input1.txt"))


N, P = list(map(int, input().strip().split()))
H = list(map(int, input().strip().split()))

count = 0
stop = False

for i in range(P):
    
    if stop:
        break
    
    hit = False
    nessuna = True
    for j in range(N):
        if not hit:
            if j == 0:
                if H[j] > H[j + 1]:
                    H[j] = 0
                    hit = True
                    count += 1
                    nessuna = False
            elif j == N - 1:
                if H[j] > H[j - 1]:
                    H[j] = 0
                    hit = True
                    count += 1
                    nessuna = False
            else:
                if H[j - 1] < H[j] > H[j + 1]:
                    H[j] = 0
                    hit = True
                    count += 1
                    nessuna = False
        else:
            hit = False
        
    if nessuna:
        stop = True
        break
        
        #print(H)

print(count)