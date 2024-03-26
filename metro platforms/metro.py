

from itertools import count
from operator import length_hint


N = int(input())

E = str(input().strip().replace(" ", ""))
W = str(input().strip().replace(" ", ""))

M = int(input())
O = str(input().strip().replace(" ", ""))

times = 0

W = W


def check(line, pos, obs, isWest, lenObs):
    if not isWest:
        obs = obs.replace(">", "v").replace("<", "^")
    else:
        obs = obs.replace(">", "^").replace("<", "v")
        obs = obs[::-1]
        
    global times
    
    #print(line, " --- ", obs, " --- ", obs[lenObs:0], " --- ", line[pos:pos+lenObs])
    
    if line[pos:pos+lenObs] == obs:
        #print("aaa", line, " --- ", obs, " --- ", line[pos:pos+lenObs])
        times += 1
        #print("sium")


for i in range(N - M + 1):
    check(E, i, O, False, M)

#print("stop")

for i in range(N - M + 1):
    check(W, i, O, True, M)






print(times)




