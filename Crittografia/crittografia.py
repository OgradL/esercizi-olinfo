#Scrivi qui il tuo codice
from __future__ import print_function
try: input = raw_input
except: pass

import sys 
sys.stdout = open("output.txt", "w")
sys.stdin = open("input.txt", "r")



N, L = map(int, input().strip().split())

S = str(input().strip())
S = [char for char in S]

for i in range(len(S)):
    try:
        S[i] = int(S[i])
    except:
        S[i] = str(S[i])


password = [''] * N


for i in range(int(L / 2)):
    #print(S[i], S[L - i - 1], type(S[i]))
    if type(S[i]) == int and type(S[L - i - 1]) == str:
        if password[S[i]] == '' or password[S[i]] == S[L - i - 1]:
            password[S[i]] = S[L - i - 1]
            #print("yuuu", password[S[i]])
        else:
            print("impossibile")
            break
    elif type(S[i]) == str and type(S[L - i - 1]) == int:
        if password[S[L - i - 1]] == '' or password[S[L - i - 1]] == S[i]:
            password[S[L - i - 1]] = S[i]
            #print("yeee", password[S[L - i - 1]])
        else:
            print("impossibile")
            break
else:
    pass
    result = "".join(password)
    
    if len(result) != N:
        #print(result)
        #print(password)
        print("impossibile")
    else:
        print(result)

