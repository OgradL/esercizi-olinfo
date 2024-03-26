#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

# input data

import os
import sys

currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input1.txt"), "r")
#sys.stdout = open(os.path.join(currentPath, "output.txt"), "w")



N = int(input().strip())
contacts = []
codes = []
for _ in range(N):
    contacts.append(input().strip())
for _ in range(10):
    codes.append(input().strip())

print(contacts)

for contact in contacts:
    #print(contact)
    for i in range(10):
        contact = contact.replace(str(codes[i]), str(i))
    
    print(contact)

