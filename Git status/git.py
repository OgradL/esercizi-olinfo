#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys
import os

currentPath = os.path.dirname(__file__)


sys.stdin = open(os.path.join(currentPath, "input2.txt"))

class dire:
    def __init__(self):
        
        self.path = ""
        self.name = ""
        
        self.sub = {
            
        }
        
        self.file = {
            
        }
        
        self.calculation = 1

    def add(self, S, changed, original):
        if len(S) > 1:
            
            current = S[0]
            #print("percorso", current, S)
            S.pop(0)
            if not current in self.sub:
                #print(self.sub)
                self.sub[current] = dire()
                self.sub[current].path = self.path + "/" + current
                self.sub[current].name = current
                #print("uf", self.sub)
                #self.sub[current].path = join(path, "/", current)
            self.sub[current].add(S, changed, original)
            #print(self.sub)
        elif len(S) == 1:
            self.file[str(original)] = changed

    def calculate(self):
        ok1 = True
        for i in self.file:
            
            ok1 = ok1 and self.file[i] == 1
            if not ok1:
                break
        
        
        ok2 = True
        
        for i in self.sub:
            
            ok2 = ok2 and self.sub[i].calculate() == 1
        
        
        if ok2 and ok1:
            self.calculation = 1
            return self.calculation
        else:
            for i in self.file:
                #pass
                if self.file[i] == 1:
                    print(i)
            
            for i in self.sub:
                #print("sub")
                #print(self.sub[i].calculation)
                if self.sub[i].calculation == 1:
                    print(self.sub[i].path)
                    #print("no sub")
                #if self.sub[i].calculate() == 1:
                #    print("osss")
                #    print(self.sub[i].path)
            
            self.calculation = 0
            return self.calculation

    def scrivi(self, depth, path):
        print(" | " * depth, end='')
        print(self.path, "  ", self.name)
        print(" | " * depth, end='')
        print(self.sub)
        for i in self.file:
            print(" | " * depth, i)
        for i in self.sub:
            print(" | " * depth, i)
            self.sub[i].scrivi(depth + 1, self.path)


root = dire()

# input data
N = int(input().strip())
for i in range(N):
    S = input().strip().split()
    M = int(S[0])
    S.pop(0)
    P = ""
    for i in S:
        P += i
    #print(P)
    original = P
    P = P.split("/")
    print(P)
    P.pop(0)
    root.add(P, M, original)

print("\n\n\n")

root.scrivi(0, "/")

print("\n\n\n")

rootIsChanged = root.calculate()


if rootIsChanged:
    print("/")

#print(42)  # print the result