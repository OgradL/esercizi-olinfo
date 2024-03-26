#Scrivi qui il tuo codice
#Scrivi qui il tuo codice
#!/usr/bin/env python3
import time




N = int(input().strip())
MAX_CORD = 200000

X = [0] * N
Y = [0] * N
for i in range(N):
    X[i], Y[i] = map(int, input().strip().split())

"""           luca
startL = time.time() * 1000

l_shapes = 0


for star_x, star_y in zip(X, Y):
    same_row = X.count(star_x) - 1
    same_column = Y.count(star_y) - 1
    if same_row and same_column:
        l_shapes += same_row * same_column

print("luca sol: ", l_shapes)

endL = time.time() * 1000
print(endL - startL)

"""
#startM = time.time() * 1000

l_shapes_2 = 0

Xdone = [-1] * MAX_CORD
Ydone = [-1] * MAX_CORD
for star_x, star_y in zip(X, Y):
    
    same_row = 0
    same_col = 0
    
    if Xdone[star_x] >= 0:
        same_row = Xdone[star_x]
    else:
        same_row = X.count(star_x) - 1
        Xdone[star_x] = same_row
    
    if Ydone[star_y] >= 0:
        same_col = Ydone[star_y]
    else:
        same_col = Y.count(star_y) - 1
        Ydone[star_y] = same_col
    
    l_shapes_2 += (same_row * same_col)

print(l_shapes_2)

#endM = time.time() * 1000
#print(endM - startM)

