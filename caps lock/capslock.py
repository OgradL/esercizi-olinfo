
from __future__ import print_function
try: input = raw_input
except: pass

import sys 
sys.stdout = open("output.txt", "w")
sys.stdin = open("input.txt", "r")
#Scrivi qui il tuo codice
N = int(input().strip())
S = str(input().strip())
S = [char for char in S]
for i in S:
    if i == i.lower():
        print(i.upper(), end='')
    else:
        print(i.lower(), end='')