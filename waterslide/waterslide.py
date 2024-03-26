
import sys
import os
import time
import random
import math


currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input0.txt"))



class node:
    def __init__(self, index):
        self.index = index
        self.parent = 0
        self.childs = []
        self.people = 0

    def search(self, nodes, people):
        
        self.people += people
        
        #print(self.childs)
        for i in self.childs:
            
            nodes[i].search(nodes, people / len(self.childs))
            #print(a)
        #if len(self.childs) == 0:
            #return [self.index]
            #print(self.index)

        #return a

N, M, P = map(int, input().strip().split())

nodes = []
for i in range(N):
    nodes.append(node(i))

for i in range(M):
    a = list(map(int, input().strip().split()))
    nodes[a[1]].parent = a[0]
    nodes[a[0]].childs.append(a[1])

"""

pools = nodes[0].search(nodes)

count = [0] * N
print(pools)
for i in pools:
    #print(i)
    count[i] += 1

index = 0
ma = 0

for i in range(len(count)):
    if ma < count[i]:
        index = i
        ma = count[i]
print(index)
"""

nodes[0].search(nodes, 1)

index = 0
ma = 0

for i in range(N - P, N):
    if nodes[i].people > ma:
        index = nodes[i].index
        ma = nodes[i].people

print(index)

#for i in nodes:
#    print(i.index, i.parent, i.childs)
    

