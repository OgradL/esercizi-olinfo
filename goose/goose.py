#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
J = list(map(int, input().strip().split()))

current = 0
count = 0
stop = False
for i in range(1, 7):
    current = 0
    count = 0
    stop = False
    for j in range(N):
        current += i
        count += 1
        if current >= N:
            print(count, end=' ')
            break
        while J[current] != 0:
            current += J[current]
            if current >= N:
                print(count, end=' ')
                stop = True
                break
        if stop:
            break

print()

#for i in range(1,7):
    #print(42, end=' ')  # print the result for die i
#print()
