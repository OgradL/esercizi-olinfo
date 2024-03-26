
class cell:
    def __init__(self, x, y, data):
        self.x = x
        self.y = y
        self.visited = False
        self.cella = data
    
    def check_near(self, board):
        self.visited = True
        a, b, c, d = False, False, False, False
        #print(self.x, self.y, self.cella)
        if board[self.x + 1][self.y].cella != '#' and not board[self.x + 1][self.y].visited:
            a = board[self.x + 1][self.y].check_near(board)
        
        if board[self.x][self.y + 1].cella != '#' and not board[self.x][self.y + 1].visited:
            b = board[self.x][self.y + 1].check_near(board)
        
        if board[self.x - 1][self.y].cella != '#' and not board[self.x - 1][self.y].visited:
            c = board[self.x - 1][self.y].check_near(board)
        
        if board[self.x][self.y - 1].cella != '#' and not board[self.x][self.y - 1].visited:
            d = board[self.x][self.y - 1].check_near(board)
        
        if self.cella == '@':
            return True
        else:
            return a or b or c or d
        
     

def split(word):
    return [char for char in word]


R, C = map(int, input().strip().split())
board = [[0] * C] * R
for i in range(R):
    board[i] = list(map(str, input().strip().split()))
    board[i] = split(board[i][0])
    #print(board[i])


for i in range(R):
    for j in range(C):
        board[i][j] = cell(i, j, board[i][j])


count = 0
e = False
for i in range(1, R - 1):
    for j in range(1, C - 1):
        #print(i, j, end=' ')
        if not board[i][j].visited and board[i][j].cella != '#':
            e = board[i][j].check_near(board)
            #print(i, j)
            if not e:
                count += 1
    #print()


print(count)