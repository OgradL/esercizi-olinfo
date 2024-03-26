#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N, M, V = list(map(int, input().strip().split()))
H = list(map(int, input().strip().split()))

G = 10

energy = 1/2 * M * V * V

differenze = [0] * (N - 1)
diff = 0
#metodo 2 bello
for i in range(N - 1):
    diff = (H[i] - H[i - 1] ) * M * G
    differenze[i] = diff





#metodo 1 brutto
"""
for i in range(N):
    count = 0
    energy = 1/2 * M * V * V
    for j in range(i, N):
        if j == N - 1:
            count = j
            break
        diff = H[j] - H[j + 1]
        current = G * M * diff
        #print(current, " (", G, " ", M, " ", diff, ") ", end=' - ')
        energy += current
        
        #print(energy)
        
        count = j
        if energy <= 0:
            break
    print(count, end=' ')
print()
"""





#for i in range(N):
#    print(42, end=" ")  # print the result
#print()
