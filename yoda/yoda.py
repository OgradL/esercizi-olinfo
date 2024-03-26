from __future__ import print_function
try: input = raw_input
except: pass

import sys 
sys.stdout = open("output.txt", "w")
sys.stdin = open("input.txt", "r")

V = list(map(str, input().strip().split()))
V.reverse()
for x in V:
    print(str(x), end = ' ')

#print(" ".join(V))
