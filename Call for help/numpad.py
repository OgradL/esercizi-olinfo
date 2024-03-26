
import math
import os
import sys
import time

currentPath = os.path.dirname(__file__)

sys.stdin = open( os.path.join(currentPath, "input.txt"))

start = time.time() * 1000000

S = str(input().strip())
N = len(S)

S = [int(char) for char in S]

X = [1] * (N + 1)
Y = [4] * (N + 1)

answer = N

for i in range(1, N + 1):
    if S[i - 1] == 0:
        X[i] = 1
        Y[i] = 4
    else:
        X[i] = (S[i - 1] - 1) % 3
        Y[i] = math.ceil(S[i - 1] / 3)
    answer += abs(X[i] - X[i - 1]) + abs(Y[i] - Y[i - 1])
    
print(answer)

end = time.time() * 1000000

print(end - start)