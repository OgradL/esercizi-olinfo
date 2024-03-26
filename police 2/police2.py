#Scrivi qui il tuo codice
#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
N = int(input().strip())
V = list(map(int, input().strip().split()))

finCount = 0
giafatte = [False] * N
for i in range(N):
    start = i
    count = 1
    current = i
    if not giafatte[current]:
        while current != N + 1:
            #print(current, V[current], giafatte[current], start)
            if giafatte[current]:
                if current != start:
                    for k in range(count + 1):
                        giafatte[current] = False
                        current = V[current]
                    count = 0
                break
            giafatte[current] = True
            current = V[current]
            count += 1
        #print(count - 1)
    finCount = max(finCount, count - 1)


print(finCount)  # print the result