from __future__ import print_function
try: input = raw_input
except: pass

import sys 
sys.stdout = open("output.txt", "w")
sys.stdin = open("input.txt", "r")

#Scrivi qui il tuo codice

import math

class star:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
        self.distance = math.sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))

def sort_key(e):
    return e.distance


def search(arr, x, start, end):
    
    while start + 1 < end:
        
        mid = int((start + end) / 2)
        
        if arr[mid].distance > x:
            end = mid
        else:
            start = mid
    
    return end



N = int(input().strip())

stars = []

for i in range(N):
    x, y, z = list(map(int, input().strip().split()))
    stars.append(star(x, y, z))

Q = int(input().strip())

stars.sort(key=sort_key)

for i in range(Q):
    
    D = int(input().strip())
    answer = 0
    answer = search(stars, D, 0, N)
    
    print(answer)

