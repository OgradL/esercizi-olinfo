#Scrivi qui il tuo codice
#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
S = [None] * N
P = [None] * N
for x in range(N):
    S[x], P[x] = map(int, input().strip().split())


maxo = 0
index = 0
current = 0
totalS = 0
totalP = 0
for i in range(N):
    if S[i] == P[i]:
        continue
    totalS = 0
    totalP = 0
    for j in range(N):
        if i == j:
            continue
        totalS += S[j]
        totalP += P[j]
        
    if maxo < totalS / totalP:
        maxo = totalS / totalP
        index = i

    
print(index)  # print the result