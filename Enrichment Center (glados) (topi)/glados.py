def split(word):
    return [char for char in word]
    


H, W, R, C = map(int, input().strip().split())
board = []

for i in range(H):
    board.append(input().strip().split())
    #print(board[i])
    #print(split(board[i]))
    #print(split(board[i][0]))
    board[i] = split(board[i][0])
    
    #print(board[i])
    



visitedR = []
visitedC = []
visitedL = []
r = R
c = C
looking = 0
a = 15

out = False
stuck = False
cycling = False

while True:
    a -= 1
    current = (looking - 1) % 4
    #print("looking: ", looking)
    #print(board[4][3])
    for i in range(4):
        
        #print("current: ", current)
        
        if current == 3:
            if board[r][c + 1] != '#':
                #print("destra")
                c += 1
                looking = 3
                break
        elif current == 0:
            if board[r - 1][c] != '#':
                #print("su")
                r -= 1
                looking = 0
                break
        elif current == 1:
            if board[r][c - 1] != '#':
                #print("sinistra")
                c -= 1
                looking = 1
                break
        else:
            if board[r + 1][c] != '#':
                #print("giu")
                r += 1
                looking = 2
                break
        current += 1
        current %= 4
    
    #print(r, c)
    
    for i in range(len(visitedR)):
        if r == visitedR[i] and c == visitedC[i] and looking == visitedL[i]:
            print("cycling")
            cycling = True
            break
    else:
        visitedR.append(r)
        visitedC.append(c)
        visitedL.append(looking)
    
    if cycling:
        break
    
    
    if board[r][c] == '.':
        pass
        
    elif board[r][c] == '@':
        stuck = True
        print("stuck")
        break
    elif board[r][c] == 'O':
        out = True
        print("free")
        break
    else:
        print("error")
        break



"""

for i in range(H):
    for j in range(W):
        print(board[i][j], end=' ')
    print()
"""

