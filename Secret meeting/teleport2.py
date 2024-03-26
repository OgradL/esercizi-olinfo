#Scrivi qui il tuo codice
#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

def avg(arr):
    if len(arr) > 0:
        return sum(arr) / len(arr)
    return 0

def dist(first, second):
    answer = (abs(first[0] - second[0]), abs(first[1] - second[1]))
    dist = math.sqrt(pow(answer[0], 2) + pow(answer[1], 2))
    return dist

import math

# input data
T = int(input().strip())

for _ in range(T):
    Xa, Ya, Xb, Yb, Xc, Yc, R = map(int, input().strip().split())
    
    
    result = 1.23456789
    
    direct = dist((Xa, Ya), (Xb, Yb))
    
    withBed = max(dist((Xa, Ya), (Xc, Yc)) - R, 0) + max(dist((Xb, Yb), (Xc, Yc)) - R, 0)
    
    result = min(direct, withBed)
    
    result = math.floor(result * 10**6) / 10**6
    print("{:.6f}".format(result))
