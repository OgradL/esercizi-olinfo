
N = int(input().strip())
p = list(map(int, input().strip().split()))
a = list(map(int, input().strip().split()))



class node:
    def __init__(self, index, label, parent, childs):
        self.index = index
        self.label = label
        self.parent = parent
        self.childs = childs

    def add_to_parent(self, nodes):
        nodes[self.parent].childs.append(self.index)

    def get_beauty_of_childs(self, nodes):
        if len(self.childs) != 0:
            arr = [self.label]
            for i in self.childs:
                arr = arr + nodes[i].get_beauty_of_childs(nodes)
            return arr
        return [self.label]

nodes = []
for i in range(N):
    nodes.append(node(i, a[i], 0, []))

for i in range(1, N):
    nodes[i].parent = p[i - 1]

#for i in range(1, N):
    nodes[i].add_to_parent(nodes)


for i in nodes:
    print(i.index, i.label, i.parent, i.childs)


print()
print("------------")
print()

for i in range(N):
    beauty = nodes[i].get_beauty_of_childs(nodes)
    arr = [0] * (max(beauty) + 1)
    
    for i in beauty:
        arr[i] += 1
    
    minn = 0
    #print(minn, arr)
    ind = 0
    for i in range(len(arr)):
        if arr[i] > minn:
            minn = arr[i]
            ind = i
        #print(minn)
            
    
    print(ind, end=' ')
