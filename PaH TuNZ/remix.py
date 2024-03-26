from __future__ import print_function
try: input = raw_input
except: pass

import sys 
sys.stdout = open("output.txt", "w")
sys.stdin = open("input.txt", "r")


N = int(input().strip())
S = str(input().strip())

S = S.replace("PaH", " ")
S = S.replace("TuNZ", " ")

S = S.split(" ")

for i in range(len(S)):
    S[i] = S[i].replace(" ", "")
    S[i] = S[i] + " "
    if S[i] == " ":
        S[i] = ""

print("".join(S))
