#!/usr/bin/env python3
import sys

from matplotlib import pyplot as plt

N, L = map(int, input().split())

segments = []
for _ in range(N):
    ints = list(map(int, sys.stdin.readline().split()))
    segments.append(((ints[0], ints[1]), (ints[2], ints[3])))

plt.axes().set_aspect('equal')
plt.axis([0, L, 0, L])
plt.tick_params(left=False, right=False, bottom=False, top=False, labelleft=False, labelbottom=False)
for s in segments:
    plt.plot([s[0][0], s[1][0]], [s[0][1], s[1][1]], 'black')
plt.show()
