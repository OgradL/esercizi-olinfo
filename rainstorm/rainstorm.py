#Scrivi qui il tuo codice
#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

class node:
    def __init__(self, index):
        self.index = index
        self.arch = []
        self.visited = False
        
    def search(self, nodes, limit):
        self.visited = True
        a = [self.index]
        for i in self.arch:
            if i[1] >= limit:
                if not nodes[i[0]].visited:
                    a = a + nodes[i[0]].search(nodes, limit)
        return a

# input data
N, M = map(int, input().strip().split())
A, B, R = [0] * M, [0] * M, [0] * M
H = [0] * M
nodes = []
allN = []
for i in range(N):
    allN.append(i)
    nodes.append(node(i))

for i in range(M):
    A[i], B[i], R[i] = map(int, input().strip().split())
    H[i] = R[i]
    nodes[A[i]].arch.append((B[i], R[i]))
    nodes[B[i]].arch.append((A[i], R[i]))

H.sort()
lo = 0
hi = len(H) - 1
while lo + 1 < hi:
    mid = int((lo + hi) / 2)
    x = H[mid]
    for i in nodes:
        i.visited = False
        #print(i.visited, end=' ')
    #print()
    res = nodes[0].search(nodes.copy(), x)
    #for i in nodes:
		
        #print(i.visited, end=' ')
    #print()
    #print(lo, mid, hi)
    #print(H)
    #print(res, allN)
    for i in res:
		
#print()

    if res == allN:
        lo = mid
        #print("lo")
    else:
        #print("hi")
        hi = mid
print(H[lo])

"""     bad, non funziona, funziona ma non va bene
mi = max(H)
for i in nodes:
    ma = 0
    for j in i.arch:
        ma = max(ma, j[1])
    mi = min(ma, mi)

print(mi)
"""


#print(H)
# insert your code here

#for i in nodes:
#    print(i.index, i.arch)


#print(42)  # print the result

"""

4 6
2 0 9
0 1 7
2 1 2
0 3 8
2 3 6
1 3 4
->
7

7 6
4 3 9
2 3 7
1 5 6
5 0 3
6 0 5
0 2 10
->
3


"""
