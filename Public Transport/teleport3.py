

import sys
import os

currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input0.txt"))


def split(word):
    return [char for char in word]


class cell:
    def __init__(self, x, y, data):
        self.x = x
        self.y = y
        self.cella = data
        self.distance = H * W

    def search(self, mappa, prev_distance, origine):
        
        #print(type(self.distance), prev_distance)
        
        self.distance = prev_distance
        #print(self.x, self.y)
        # ------------ a -- su --------------------
        
        if self.x > 0:
            current = mappa[self.y][self.x - 1]
            if current.distance > self.distance + 1:
                
                #print(self.x, " ", self.y, "   ->   ", current.x, " ", current.y, " si")
                
                #print(self.distance, "  -->  ", current.distance)
                
                mappa = mappa[self.y][self.x - 1].search(mappa, self.distance + 1, origine)
            #else:
            #    print(self.x, " ", self.y, "   ->   ", current.x, " ", current.y, " no")
        # ------------ b -- sinistra --------------------
        
        if self.y > 0:
            current = mappa[self.y - 1][self.x]
            if current.distance > self.distance + 1:
                
                #print(self.x, " ", self.y, "   ->   ", current.x, " ", current.y, " si")
                
                #print(self.distance, "  -->  ", current.distance)
                
                mappa = mappa[self.y - 1][self.x].search(mappa, self.distance + 1, origine)
            #else:
            #    print(self.x, " ", self.y, "   ->   ", current.x, " ", current.y, " no")
        # ------------ c -- giu --------------------
        
        if self.x < W - 1:
            current = mappa[self.y][self.x + 1]
            if current.distance > self.distance + 1:
                
                #print(self.x, " ", self.y, "   ->   ", current.x, " ", current.y, " si")
                
                #print(self.distance, "  -->  ", current.distance)
                
                mappa = mappa[self.y][self.x + 1].search(mappa, self.distance + 1, origine)
            #else:
            #    print(self.x, " ", self.y, "   ->   ", current.x, " ", current.y, " no")
        # ------------ d -- destra --------------------
        
        if self.y < H - 1:
            current = mappa[self.y + 1][self.x]
            if current.distance > self.distance + 1:
                
                #print(self.x, " ", self.y, "   ->   ", current.x, " ", current.y, " si")
                
                #print(self.distance, "  -->  ", current.distance)
                
                mappa = mappa[self.y + 1][self.x].search(mappa, self.distance + 1, origine)
            #else:
            #    print(self.x, " ", self.y, "   ->   ", current.x, " ", current.y, " no")
        
        
        
        return mappa
        




H, W = map(int, input().strip().split())

mappa = [['.'] * W] * H

Mx = 0
My = 0
Cx = 0
Cy = 0

#current = ""
for i in range(H):
    #print(current)
    mappa[i] = input().strip().replace(" ", "")
    #print(current, len(current))
    #print(current[0], split(current[0]))
    mappa[i] = split(mappa[i])
    #print(current, len(current))
    
    for j in range(W):
        mappa[i][j] = cell(j, i, mappa[i][j])
        if mappa[i][j].cella == 'M':
            #print("municipio, ", j, i)
            print(" qui", end=' ')
            Mx = j
            My = i
            mappa[i][j].distance = 0
        
        print(mappa[i][j].x, mappa[i][j].y, end='  ')
        
        
        if mappa[i][j].cella == 'C':
            #print("Casa, ", j, i)
            Cx = j
            Cy = i
            #mappa[i][j].distance = 0
            
    
    print()

mappa = mappa[My][Mx].search(mappa, 0, 'm')

#mappa = mappa[Cy][Cx].search(mappa, 0, 'c')


for i in mappa:
    for j in i:
        print(j.distance, end=' ')
    print()


"""
print("\n")

for i in mappa:
    for j in i:
        print(j.distance['c'], end=' ')
    print()
"""
