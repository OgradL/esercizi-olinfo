#Scrivi qui il tuo codice

class cell:
    def __init__(self, x, y, cella):
        self.x = x
        self.y = y
        self.cella = cella
        self.distance = 200 * 200
    
    def calculate(self, board, distance):
        
        self.distance = distance
        
        for i in range(self.x + 1):
            #if i == self.x:
                #continue
            if board[self.y][self.x - i].distance > self.distance + 1:
                if not board[self.y][self.x - i].cella == "#":
                    board[self.y][self.x - i].calculate(board, self.distance + 1)
                else:
                    break
        
        for i in range(self.x, N):
            if i == self.x:
                continue
            if board[self.y][i].distance > self.distance + 1:
                if not board[self.y][i].cella == "#":
                    board[self.y][i].calculate(board, self.distance + 1)
                else:
                    break
        
        for i in range(self.y + 1):
            #if i == self.y:
                #continue
            if board[self.y - i][self.x].distance > self.distance + 1:
                if not board[self.y - i][self.x].cella == "#":
                    board[self.y - i][self.x].calculate(board, self.distance + 1)
                else:
                    break
        
        for i in range(self.y, N):
            if i == self.y:
                continue
            if board[i][self.x].distance > self.distance + 1:
                if not board[i][self.x].cella == "#":
                    board[i][self.x].calculate(board, self.distance + 1)
                else:
                    break
        
        


N = int(input())

board = [[""] * N] * N

for i in range(N):
    board[i] = str(input().strip().replace(" ", ""))
    
    board[i] = [char for char in board[i]]
    for j in range(N):
        board[i][j] = cell(j, i, board[i][j])



board[0][0].calculate(board, 0)

if board[N - 1][N - 1].distance == 40000:
    print(-1)
else:
    print(board[N - 1][N - 1].distance - 1)

"""

for i in board:
    for j in i:
        print(j.cella, end='   ')
    print()

print("\n\n")
for i in board:
    for j in i:
        if j.distance == 40000:
            j.distance = "x"
        print(j.distance, end='   ')
    print()
    #print(*i)

"""
"""

6
T....#
####.#
...#.#
.#...#
.#####
.....T






"""