#Scrivi qui il tuo codice
#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

# input data
N, D = map(int, input().strip().split())
P = list(map(int, input().strip().split()))

result = 0
j = 0
for i in range(N):
    j = i + 1
    if j < N:
        while abs(P[i] - P[j]) < D:
            result += 1
            j += 1
            if j >= N:
                break



print(result)  # print the result