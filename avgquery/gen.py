
from random import randint

N = 100
Q = 2000

print(N, Q)

print(" ".join(list(map(str, [randint(1, 10**9) for _ in range(N)]))))

for _ in range(Q):
    op = randint(0, 1)
    if op == 0:
        print(op, randint(0, N-1), randint(1, 10**9))
    else:
        K = randint(0, 10**9)
        left, right = randint(0, N-1), randint(0, N-1)
        left, right = min(left, right), max(left, right)
        print(op, left, right+1, K)
