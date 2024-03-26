
import time


N, K = list(map(int, input().strip().split()))

sample = [[""] * N] * N

for i in range(N):
    sample[i] = str(input().strip())
    sample[i] = [char for char in sample[i]]

#print(sample)




#board = [["."] * (N ** K)] * (N ** K)

board = []
for i in range(N ** K):
    board.append([])
    for j in range(N ** K):
        board[i].append('.')

maxSize = N ** K


#for i in board:
#    print(*i)




for i in range(len(board)):
    for j in range(len(board[i])):
        color = False
        #print("\n")
        for k in range(K + 1):
            #print(i, j, N, k, N**k)
        #    print(i, N**k, N)
            x = int(i / ( N**k) ) % N
            y = int(j / ( N**k) ) % N
        #    print(x, y)
            if sample[x][y] == '.':
                samp = False
            else:
                samp = True
            color = color or samp
        #print(color)
        if color:
        #    print("black")
            color = '*'
        else:
        #    print("white", )
            color = '.'
        #print(i, j, color)
        board[i][j] = color
        
        #print()
        #for bo in board:
        #    for ba in bo:
        #        print(ba, end=' ')
        #    print()
        
        #print()
        
        #time.sleep(1)



for i in board:
    for j in i:
        print(j, end='')
    print()
print()










"""       bad, not working 2
for i in range(1, K + 1):
    size = (N ** (K - i))
    count = int(maxSize / size)
    
    print(size, count)
    
    print()
    for g in board:
        print(*g)
    print()
    
    for j in range(count):
        for k in range(count):
            print(j, k)
            print(sample[k%N][j%N])
            for x in range(j*size, j*size + size):
                for y in range(k*size, k*size + size):
                    print(x, y)
                    if board[y][x] == '.':
                        board[y][x] = sample[k%N][j%N]
                    #print(sample[k%N][j%N])
            print()
            for g in board:
                print(*g)
            print()
            time.sleep(2)
        
    
    
    pass









"""



"""         bad, not working
for i in range(K - 1):
    newBoard = [[""] * 2 * len(board)] * 2 * len(board)
    for i in range(len(board)):
        for j in range(len(board[i])):
            print(*board[i])
            if board[i][j] == ".":
                print(i, j, "white")
                newBoard[i*2][j*2] = sample[i%2][j%2]
                newBoard[i*2+1][j*2] = sample[i%2][j%2]
                newBoard[i*2][j*2+1] = sample[i%2][j%2]
                newBoard[i*2+1][j*2+1] = sample[i%2][j%2]
            else:
                print(i, j, "black")
                newBoard[i*2][j*2] = "*"
                newBoard[i*2+1][j*2] = "*"
                newBoard[i*2][j*2+1] = "*"
                newBoard[i*2+1][j*2+1] = "*"
    
    board = newBoard.copy()
"""


