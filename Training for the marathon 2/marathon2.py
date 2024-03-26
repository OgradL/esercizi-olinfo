
import sys
import os

currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input0.txt"))


N, M = map(int, input().strip().split())

C = list(map(int, input().strip().split()))
K, C = C[0], C[1:]

U = [0] * M
V = [0] * M
W = [0] * M
for i in range(M):
    U[i], V[i], W[i] = map(int, input().strip().split())


class arch:
    def __init__(self, first, second, w):
        self.first = first
        self.second = second
        self.w = w

class node:
    def __init__(self, index):
        self.index = index
        self.archi = []
        self.distance = N * M * M * N
        #self.visited = False

    def calculate(self, distance, running, nodes, visitati):
        
        self.distance = distance
        #self.visited = True
        
        if self.index in C:
            if running:
                running = False
            else:
                running = True
        
        
        visitati.append(self.index)
        
        maxDistance = N * N * M * M
        a, b = 0, 0
        none = True
        for i in self.archi:
            current = nodes[i.second]
            if not current.index in visitati:
                none = False
                if running:
                    if current.distance < distance + i.w:
                        a = i.w + current.calculate(distance + i.w, running, nodes.copy(), visitati)
                        maxDistance = max(a, maxDistance)
                else:
                    if current.distance < distance:
                        b = current.calculate(distance, running, nodes.copy(), visitati)
                        maxDistance = max(b, maxDistance)
                    
            
        
        
        
        
        return maxDistance
        
        
    

nodes = []

for i in range(N):
    nodes.append(node(i))
for i in range(M):
    nodes[V[i]].archi.append(arch(V[i], U[i], W[i]))
    nodes[U[i]].archi.append(arch(U[i], V[i], W[i]))



print("\n\n\n")


for i in nodes:
    print(i.index, end='   --  ')
    for j in i.archi:
        print(j.first, j.second, j.w, end="  --  ")
    print()

result = nodes[0].calculate(0, True, nodes, [0])

for i in nodes:
    print(i.index, i.distance)

