import random

N = 1000
M = 2000

edges = []

for _ in range(M):
    while True:
        a = random.randint(1, N)
        b = random.randint(1, N)
        if a != b:
            break

    edges.append((a, b))

random.shuffle(edges)

print(N, M)
for a, b in edges:
    print(a, b)
