
import sys
import os

currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input0.txt"))


def split(word):
    return [char for char in word]



class cell:
    def __init__(self, data, x, y):
        self.visited = False
        self.cella = data
        self.x = x
        self.y = y
        
    def check(self, mappa):
        self.visited = True
        a, b, c, d = data(), data(), data(), data()
        
        x = self.x
        y = self.y
        
        print("start ", x, y, self.cella)
        
        
        if y < H - 1:
            current = mappa[y + 1][x]
            if not current.visited:
                if current.cella != '#':
                    if current.cella == '.':
                        a = mappa[y + 1][x].check(mappa)
                        print("a", f"--->   {(x + 1)}, {y}     ")
                    elif current.cella == '@':
                        a.step = 1
                else:
                    a.step = pow(H + 10, W + 10)
            else:
                a.step = pow(H + 10, W + 10)
        else:
            a.step = pow(H + 10, W + 10)
            #print("a:", current.cella, a.step, a.raggiunto)
        if y > 1:
            current = mappa[y - 1][x]
            if not current.visited:
                if current.cella != '#':
                    if current.cella == '.':
                        b = mappa[y - 1][x].check(mappa)
                        print("b", f"--->   {(x + 1)}, {y}     ")
                    elif current.cella == '@':
                        b.step = 1
                else:
                    b.step = pow(H + 10, W + 10)
            else:
                b.step = pow(H + 10, W + 10)
        else:
            b.step = pow(H + 10, W + 10)
            #print("b:", current.cella, b.step, b.raggiunto)
        if x < W - 1:
            current = mappa[y][x + 1]
            if not current.visited:
                if current.cella != '#':
                    if current.cella == '.':
                        c = mappa[y][x + 1].check(mappa)
                        print("c", f"--->   {(x + 1)}, {y}     ")
                    elif current.cella == '@':
                        c.step = 1
                else:
                    c.step = pow(H + 10, W + 10)
            else:
                c.step = pow(H + 10, W + 10)
        else:
            c.step = pow(H + 10, W + 10)
            #print("c:", current.cella, c.step, c.raggiunto)
        if x >= 1:
            current = mappa[y][x - 1]
            if not current.visited:
                if current.cella != '#':
                    if current.cella == '.':
                        d = mappa[y][x - 1].check(mappa)
                        print("d", f"--->   {(x + 1)}, {y}     ")
                    elif current.cella == '@':
                        d.step = 1
                else:
                    d.step = pow(H + 10, W + 10)
            else:
                d.step = pow(H + 10, W + 10)
        else:
            d.step = pow(H + 10, W + 10)
            #print("d:", current.cella, d.step, d.raggiunto)
        
        
        print(x, y, " fine ")
    
        print(a.step, b.step, c.step, d.step)
        
        print(a.raggiunto, b.raggiunto, c.raggiunto, d.raggiunto)
        
        print()
        
        minn = min(min(a.step, b.step), min(c.step, d.step)) + 1
        returning = data()
        returning.raggiunto = False
        returning.step = minn
        print("ret ", returning.step)
        return returning
        



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
        mappa[i][j] = cell(current[j], j, i)
        if current[j] == 'M':
            #print("municipio, ", j, i)
            Mx = j
            My = i
            mappa[i][j].visited == True
        elif current[j] == 'C':
            #print("Casa, ", j, i)
            Cx = j
            Cy = i
            mappa[i][j].visited == True


class data:
    def __init__(self):
        self.raggiunto = False
        self.step = 0


def check(mappa, x, y, uffa):
    mappa[y][x].visited = True
    a, b, c, d = data(), data(), data(), data()
    
    print(x, y, " start ", uffa)
    
    if y < H - 1:
        current = mappa[y + 1][x]
        if not current.visited:
            if current.cella != '#':
                if current.cella == '.':
                    a = check(mappa, x, y + 1, 'a')
                    print("a", f"--->   {(x + 1)}, {y}     ")
                elif current.cella == '@':
                    a = data()
                    #a.step = 1
            else:
                a = data()
                a.step = pow(H + 10, W + 10)
        print("a:", current.cella, a.step, a.raggiunto)
    if y > 1:
        current = mappa[y - 1][x]
        if not current.visited:
            if current.cella != '#':
                if current.cella == '.':
                    b = check(mappa, x, y - 1, 'b')
                    print("b", f"--->   {(x + 1)}, {y}     ")
                elif current.cella == '@':
                    b = data()
                    #b.step = 1
            else:
                b = data()
                b.step = pow(H + 10, W + 10)
        #print("b:", current.cella, b.step, b.raggiunto)
    if x < W - 1:
        current = mappa[y][x + 1]
        if not current.visited:
            if current.cella != '#':
                if current.cella == '.':
                    c = check(mappa, x + 1, y, 'c')
                    print("c", f"--->   {(x + 1)}, {y}     ")
                elif current.cella == '@':
                    c = data()
                    #c.step = 1
            else:
                c = data()
                c.step = pow(H + 10, W + 10)
        #print("c:", current.cella, c.step, c.raggiunto)
    if x >= 1:
        current = mappa[y][x - 1]
        if not current.visited:
            if current.cella != '#':
                if current.cella == '.':
                    d = check(mappa, x - 1, y, 'd')
                    print("d", f"--->   {(x + 1)}, {y}     ")
                elif current.cella == '@':
                    d = data()
                    #d.step = 1
            else:
                d = data()
                d.step = pow(H + 10, W + 10)
        #print("d:", current.cella, d.step, d.raggiunto)
    """
    if a.raggiunto:
        return a
    if b.raggiunto:
        return b
    if c.raggiunto:
        return c
    if d.raggiunto:
        return d
    """
    
    print(x, y, " fine ")
    
    print(a.step, b.step, c.step, d.step)
    
    print(a.raggiunto, b.raggiunto, c.raggiunto, d.raggiunto)
    
    print()
    
    minn = min(min(a.step, b.step), min(c.step, d.step)) + 1
    returning = data()
    returning.raggiunto = False
    returning.step = minn
    print("ret ", returning.step)
    return returning


print("My, Mx", My, Mx)
print("Cy, Cx", Cy, Cx)

municipio = mappa[My][Mx].check(mappa)
casa = mappa[Cy][Cx].check(mappa)



risposta2 = municipio.step + casa.step + 1
print(municipio.step, casa.step)
if municipio.raggiunto or casa.raggiunto:
    if municipio.raggiunto:
        g = municipio.step
        h = g + 1
    if casa.raggiunto:
        h = casa.step
        if not municipio.raggiunto:
            g = h + 1
        
    risposta1 = min(h, g) + 1
    print("risposta1" , risposta1)
else:
    risposta1 = risposta2 + 23
print("risposta2" , risposta2)
print(min(risposta1, risposta2))

#print(H, W)

#for i in mappa:
#    print(i)