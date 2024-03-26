#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N, K = map(int, input().strip().split())
C = list(map(int, input().strip().split()))
T = []
Q = []
for _ in range(K):
	t, q = map(int, input().strip().split())
	T.append(t)
	Q.append(q)

# insert your code here

# N -> Number of trash bins
# K -> Days before going to Milano
# C (list) -> Capacities of trash bins

# T -> Type of trash
# Q -> Number of bags

totalCost = 0.0
counter = 0

trashBins = [0] * N

def addBags(typeOfTrash, nOfBags):
    global totalCost, counter
    if trashBins[typeOfTrash] + (nOfBags / C[typeOfTrash]) > 1: # Allora il cestino si sta sfondando -> Bisogna prima pulirlo
        totalCost += (C[typeOfTrash] - (trashBins[typeOfTrash] * C[typeOfTrash]))
        trashBins[typeOfTrash] = 0
        trashBins[typeOfTrash] += trashBins[typeOfTrash] + (nOfBags / C[typeOfTrash])
    else:
        trashBins[typeOfTrash] += trashBins[typeOfTrash] + (nOfBags / C[typeOfTrash])
        counter += 1

for day in range(K):
    addBags(T[day], Q[day])

##### L'ultimo giorno si pulsice tutto #####

'''
nothingToClean = False

# tolgo tutti gli zeri alla fine
while trashBins[-1] == 0:
    if len(trashBins) == 1:
        nothingToClean = True
        break
    trashBins.pop()
    C.pop()
# tolgo tutti gli zeri all'inizio
while trashBins[0] == 0:
    if len(trashBins) == 1:
        nothingToClean = True
        break
    trashBins.pop(0)
    C.pop(0)

if not nothingToClean:
    for i in range(len(trashBins)):
        totalCost += C[i] - (trashBins[i] * C[i])
        
'''


for i in range(len(trashBins)):
    if trashBins[i] != 0:
        totalCost += (C[i] - (trashBins[i] * C[i]))
    
    
print(int(totalCost))  # print the result
