



H, W = list(map(int, input().strip().split()))

MAX = 4800000

mappa = [[0] * W] * H

for i in range(H):
    mappa[i] = list(map(int, input().strip().split()))
    

visited = [[False] * W] * H

def search(x, y, provenienzaX, provenienzaY, mappa):
    
    XP = 0
    XN = 0
    YP = 0
    YN = 0
    
    if x > 0:
        currX = x - 1
        currY = y
        if (currX, currY) != (provenienzaX, provenienzaY):
            XN = (mappa[y][x] - mappa[currY][currX], abs(mappa[y][x] - mappa[currY][currX]))
        else:
            XN = (MAX,MAX)
        
    
    if x < W - 1:
        currX = x + 1
        currY = y
        if (currX, currY) != (provenienzaX, provenienzaY):
            XP = (mappa[y][x] - mappa[currY][currX], abs(mappa[y][x] - mappa[currY][currX]))
        else:
            XP = (MAX,MAX)
    
    if y > 0:
        currX = x
        currY = y - 1
        if (currX, currY) != (provenienzaX, provenienzaY):
            YN = (mappa[y][x] - mappa[currY][currX], abs(mappa[y][x] - mappa[currY][currX]))
        else:
            YN = (MAX,MAX)
    
    if y < H - 1:
        currX = x
        currY = y + 1
        if (currX, currY) != (provenienzaX, provenienzaY):
            YP = (mappa[y][x] - mappa[currY][currX], abs(mappa[y][x] - mappa[currY][currX]))
        else:
            YP = (MAX,MAX)
    
    minStep = min(min(XN[1], XP[1]), min(YN[1], YP[1]))
    
    #if 

