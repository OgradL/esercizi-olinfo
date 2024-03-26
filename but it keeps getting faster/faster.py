#Scrivi qui il tuo codice

import math

W = str(input().strip())
N = int(input().strip())

C = [""] * N

for i in range(N):
    C[i] = str(input().strip())

time = 0
speed = 1

count = 0

for i in range(N):
    time += 1 / speed
    
    #print(time, speed, count)
    time = round(time, 3)
    if time == float(round(time)):
        time = round(time, 3)
        speed += count
        count = 0
        #print("pizza")
    
    #print(C[i], W, C[i] == W)
    if C[i] == W:
        count += 1
    

print(math.floor(time))
