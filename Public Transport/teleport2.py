
from asyncio.windows_events import NULL
import sys
import os

currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input0.txt"))


def split(word):
    return [char for char in word]


class dati:
    def __init__(self):
        self.steps = 1
        self.distance = pow(H + 10, W + 10)
        self.reached = False
        #self.distanceMuni = pow(H + 10, W + 10)


class cell:
    def __init__(self, x, y, data):
        self.x = x
        self.y = y
        self.cella = data
        self.distance = {
            'm': pow(H + 10, W + 10),
            'c': pow(H + 10, W + 10)
        }
    
    def check(self, mappa, origine, distancee):
        
        self.distance[origine] = distancee
        
        print(self.x, " ", self.y)
        if distancee != 0:
            if self.x == Cx and self.y == Cy:
                ritorno = dati()
                ritorno.distance = 1
                ritorno.reached = True
                return ritorno
            if self.x == Mx and self.y == My:
                ritorno = dati()
                ritorno.distance = 1
                ritorno.reached = True
                return ritorno
        
        
        
        a, b, c, d = NULL, NULL, NULL, NULL
        
        # ------------ a -- su --------------------
        
        print(self.x, self.y, self.cella, end=' ')
        
        if self.x > 0:
            #print("su")
            current = mappa[self.y][self.x - 1]
            if current.distance[origine] > self.distance[origine] + 1:
                if current.cella != '#':
                    if current.cella == '.':
                        print("a, su")
                        a = current.check(mappa, origine, self.distance[origine] + 1)
                    elif current.cella == '@':
                        a = dati()
        if a == NULL:
            a = dati()
            a.steps = pow(H + 10, W + 10)
        
        # ------------ b -- sinistra --------------------
        
        if self.y > 0:
            #print("sinistra")
            current = mappa[self.y - 1][self.x]
            if current.distance[origine] > self.distance[origine] + 1:
                if current.cella != '#':
                    if current.cella == '.':
                        print("b, sinistra")
                        #print(current.distance[origine], self.distance[origine] + 1)
                        b = current.check(mappa, origine, self.distance[origine] + 1)
                    elif current.cella == '@':
                        b = dati()
        if b == NULL:
            b = dati()
            b.steps = pow(H + 10, W + 10)
        
        # ------------ c -- giu --------------------
        
        if self.x < W - 1:
            #print("giu")
            current = mappa[self.y][self.x + 1]
            if current.distance[origine] > self.distance[origine] + 1:
                if current.cella != '#':
                    if current.cella == '.':
                        print("c, giu")
                        c = current.check(mappa, origine, self.distance[origine] + 1)
                    elif current.cella == '@':
                        c = dati()
        if c == NULL:
            c = dati()
            c.steps = pow(H + 10, W + 10)
        
        # ------------ d -- destra --------------------
        
        if self.y < H - 1:
            #print("destra")
            current = mappa[self.y + 1][self.x]
            if current.distance[origine] > self.distance[origine] + 1:
                if current.cella != '#':
                    if current.cella == '.':
                        print("d, destra")
                        d = current.check(mappa, origine, self.distance[origine] + 1)
                    elif current.cella == '@':
                        d = dati()
        if d == NULL:
            d = dati()
            d.steps = pow(H + 10, W + 10)
        
        # --------------------  fine  --------------------

        arr1 = [a, b, c, d]
        minRaggiunto = pow(H + 10, W + 10)
        raggiunto = a.reached or b.reached or c.reached or d.reached
        for i in arr1:
            if i.reached:
                minRaggiunto = min(minRaggiunto, a.distance)
        
        minSteps = pow(H + 10, W + 10)
        
        for i in arr1:
            minSteps = min(minSteps, i.steps)
        
        ritorno = dati()
        ritorno.distance = minRaggiunto
        ritorno.steps = minSteps + 1
        ritorno.reached = raggiunto
        
        return ritorno
        


H, W = map(int, input().strip().split())

mappa = [['.'] * W] * H

Mx = 0
My = 0
Cx = 0
Cy = 0

current = []
for i in range(H):
    current = input().strip().replace(" ", "")
    #print(current, len(current))
    #print(current[0], split(current[0]))
    current = split(current)
    #print(current, len(current))
    
    for j in range(W):
        mappa[i][j] = cell(j, i, current[j])
        if current[j] == 'M':
            #print("municipio, ", j, i)
            Mx = j
            My = i
            mappa[i][j].distance = 0
        elif current[j] == 'C':
            #print("Casa, ", j, i)
            Cx = j
            Cy = i
            mappa[i][j].distance = 0


casa = mappa[Cy][Cx].check(mappa, 'c', 0)

print(casa.reached, casa.steps, casa.distance)
print()

municipio = mappa[My][Mx].check(mappa, 'm', 0)

print(municipio.reached, municipio.steps, municipio.distance)

tempo = min(casa.steps + municipio.steps + 1, min(casa.distance, municipio.distance))

print(tempo)




