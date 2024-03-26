#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


class car:
    def __init__(self, a, b, c, index):
        self.a = a
        self.b = b
        self.c = c
        #self.tot = a * t * t + b * t + c
        self.index = index

class val:
    def __init__(self, valore, index):
        self.val = valore
        self.index = index

def key_sort(e):
    return e.val

N = int(input().strip())

A = [0] * N
B = [0] * N
C = [0] * N
for i in range(N):
    A[i], B[i], C[i] = map(int, input().strip().split())


Q = int(input().strip())

P = [0] * Q
T = [0] * Q
for i in range(Q):
    P[i], T[i] = map(int, input().strip().split())

auto = []

for i in range(N):
    auto.append(car(A[i], B[i], C[i], i + 1))

valori = [ [val(0, 0)] * N ] * (max(T) + 1)
ready = [False] * (max(T) + 1)


#print(P[Q - 1])

for i in range(Q):
    #print(i)
    if not ready[T[i]]:
        #print("not ready", i)
        ready[T[i]] = True
        for j in range(len(valori[T[i]])):
            valori[T[i]][j] = val( auto[j].a * T[i] * T[i] + auto[j].b * T[i] + auto[j].c , auto[j].index)
        valori[T[i]].sort(key=key_sort)
    else:
        print(i)
    
    print(valori[i][P[i] - 1].index)


for i in valori:
    for j in i:
        print(j.val, j.index, end=' ')
    print()

"""
for i in range(Q):
    if T[i] == 1:
        print(posi1[P[i] - 1].index)
    elif T[i] == 0:
        print(posi0[P[i] - 1].index)
    else:
        print(posi2[P[i] - 1].index)
"""