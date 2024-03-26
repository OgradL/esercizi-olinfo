#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


def init(N, X, Y):
    # insert your code here...
    pass

def toggle_edge(x, y):
    # ...and here...
    pass

def is_reachable(x, y):
    # ...and also here
    return True



N, Q = map(int, input().strip().split())

X = [0] * (N - 1)
Y = [0] * (N - 1)

for i in range(N - 1):
    X[i], Y[i] = map(int, input().strip().split())

init(N, X, Y)
tot = 0
for i in range(Q):
    t, x, y = map(int, input().strip().split())
    if t == 1:
        toggle_edge(x, y)
    else:
        x = (x + tot) % N + 1
        y = (y + tot) % N + 1
        ans = int(is_reachable(x, y))
        print(ans)
        tot += ans
