#Scrivi qui il tuo codice

import sys
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")




class cell:
    def __init__(self, x, y, cella):
        self.x = x
        self.y = y
        self.cella = cella
        self.distance = 100 * 100
    
    def calculate(self, mappa, distance):
        
        self.distance = distance
        
        if self.x > 0:
            if mappa[self.y][self.x - 1].distance > self.distance + 1:
                if mappa[self.y][self.x - 1].cella == '*':
                    mappa[self.y][self.x - 1].calculate(mappa, self.distance + 1)
        
        if self.x < N - 1:
            if mappa[self.y][self.x + 1].distance > self.distance + 1:
                if mappa[self.y][self.x + 1].cella == '*':
                    mappa[self.y][self.x + 1].calculate(mappa, self.distance + 1)
        
        
        if self.y > 0:
            if mappa[self.y - 1][self.x].distance > self.distance + 1:
                if mappa[self.y - 1][self.x].cella == '*':
                    mappa[self.y - 1][self.x].calculate(mappa, self.distance + 1)
        
        if self.y < N - 1:
            if mappa[self.y + 1][self.x].distance > self.distance + 1:
                if mappa[self.y + 1][self.x].cella == '*':
                    mappa[self.y + 1][self.x].calculate(mappa, self.distance + 1)
        
        
        
        if self.x > 0 and self.y > 0:
            if mappa[self.y - 1][self.x - 1].distance > self.distance + 1:
                if mappa[self.y - 1][self.x - 1].cella == '*':
                    mappa[self.y - 1][self.x - 1].calculate(mappa, self.distance + 1)
        
        if self.x < N - 1 and self.y > 0:
            if mappa[self.y - 1][self.x + 1].distance > self.distance + 1:
                if mappa[self.y - 1][self.x + 1].cella == '*':
                    mappa[self.y - 1][self.x + 1].calculate(mappa, self.distance + 1)
        
        if self.x > 0 and self.y < N - 1:
            if mappa[self.y + 1][self.x - 1].distance > self.distance + 1:
                if mappa[self.y + 1][self.x - 1].cella == '*':
                    mappa[self.y + 1][self.x - 1].calculate(mappa, self.distance + 1)
        
        if self.x < N - 1 and self.y < N - 1:
            if mappa[self.y + 1][self.x + 1].distance > self.distance + 1:
                if mappa[self.y + 1][self.x + 1].cella == '*':
                    mappa[self.y + 1][self.x + 1].calculate(mappa, self.distance + 1)
        
        




N = int(input())

mappa = [[''] * N] * N

for i in range(N):
    mappa[i] = [char for char in str(input().strip())]
    for j in range(len(mappa[i])):
        mappa[i][j] = cell(j, i, mappa[i][j])
    

mappa[0][0].calculate(mappa, 1)

print(mappa[N-1][N-1].distance)



#for i in mappa:
    #for j in i:
        #if j.distance == 100*100:
            #j.distance = -1
        #print(j.x, j.y, j.distance, " ", end='')
    #print()
