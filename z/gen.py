
from random import randint
from sys import argv

N = 10**12
Q = 10**5

if len(argv) >= 3:
    exec(str(argv[1]))
    exec(str(argv[2]))

print(N, Q)

for _ in range(Q):
    x, y = randint(0, N), randint(0, 2)
    print(x, y)
