import os
import sys

currentPath = os.path.dirname(__file__)
#sys.stdin = open(os.path.join(currentPath, 'input.txt'))

N, D = map(int, input().strip().split())
S = []
for i in range(N):
    S.append(input().strip())
    S[i] = [char for char in S[i]]
    for j in range(len(S[i])):
        S[i][j] = ord(S[i][j]) - 96


#print(S)

current = []

done = []

count = [1] * N

for i in S:
    val = min(i) - 1
    for k in range(len(i)):
        i[k] -= val
    
    #print("-----------")
    #print(i)
    #print(done)
    #print(len(done))
    #print(count)
    
    for j in range(len(done)):
        if done[j] == i:
            count[j] += 1
            
    else:
        done.append(i)
        #count[i] += 1
    
    #print(i)
    #print(done)
    #print(len(done))
    #print(count)
    
    #print("-----------------")
    
    
print(max(count))
#print(count)
