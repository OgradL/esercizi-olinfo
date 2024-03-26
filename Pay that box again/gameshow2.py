#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
V = list(map(int, input().strip().split()))
P = list(map(int, input().strip().split()))
C = list(map(int, input().strip().split()))

start = 0
currentMoney = 0
totalPositiveGain = 0

for i in range(N):
    
    if V[i] - P[i] > C[i]:
        #print("compro", i)
        if currentMoney < P[i]:
            totalPositiveGain += V[i]
            #print("not enough", end=' ')
            start += P[i] - currentMoney
            currentMoney = 0
            #print(start)
        else:
            currentMoney += (V[i] - P[i])
    else:
        #print("passo", i)
        currentMoney += C[i]
    #print(currentMoney)
    

finalMoney = totalPositiveGain + currentMoney - start

print(finalMoney, start)  # print the result
