#!/usr/bin/env python3

N = int(input().strip())

isograms = 0

for i in range(N):
    S = input().strip().upper()
    for letter in set(S):
        if not letter.isalpha():
            continue
        if S.count(letter) > 2:
            break
    else:
        isograms += 1

print(isograms)
