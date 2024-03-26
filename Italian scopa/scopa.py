
import time
import os
import sys
import math

H = list(map(str, input().strip().split()))

T = list(map(str, input().strip().split()))

for i in range(len(H)):
    H[i] = [char for char in T[i]]

for i in range(len(T)):
    T[i] = [char for char in T[i]]
        

done = False

while not done:
    
    sette = False
    
    for j in H:
        if j[0] == '7' and j[1] == 'G':
            sette = True
    for j in T:
        if j[0] == '7' and j[1] == 'G':
            sette = True


