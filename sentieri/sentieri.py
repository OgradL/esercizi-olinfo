
class node:
    def __init__(self, index):
        self.index = index
        self.archi = []
        self.visited = False

    def add(self, connecion, bollente):
        self.archi.append((connecion, bollente))
    
    def search(self, nodes):
        
        if self.index == N - 1:
            return (0, [self.index])
        
        percorso = []
        
        self.visited = True
        a = N
        for i in self.archi:
            if not nodes[i[0]].visited:
                res = nodes[i[0]].search(nodes.copy())
                
                if i[1]:
                    if res[0] < a:
                        a = res[0] + 1
                        percorso = res[1]
                    #a = min(res[0], a) + 1
                else:
                    if res[0] < a:
                        a = res[0]
                        percorso = res[1]
                    #a = min(res[0], a)
        
        return (a, percorso + [self.index])



N, A, B = list(map(int, input().strip().split()))

S = [(0, 0)] * A
SB = [(0, 0)] * B

nodes = [node(i) for i in range(N)]

for i in range(A):
    S[i] = tuple(map(int, input().strip().split()))
    nodes[S[i][0] - 1].add(S[i][1] - 1, False)
    nodes[S[i][1] - 1].add(S[i][0] - 1, False)

for i in range(B):
    SB[i] = tuple(map(int, input().strip().split()))
    nodes[SB[i][0] - 1].add(SB[i][1] - 1, True)
    nodes[SB[i][1] - 1].add(SB[i][0] - 1, True)


answer = nodes[0].search(nodes)

print(answer)

for i in nodes:
    print(i.index, i.archi)



