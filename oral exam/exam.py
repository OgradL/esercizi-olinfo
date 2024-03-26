N = int(input())
V = list(map(int, input().strip().split()))
count = 0
out = []
for i in range(101):
    count = 0
    for j in range(N):
        #print(j)
        if V[j] >= i:
            count += 1
    out.append(count)
out.reverse()
for x in range(101):
    print(out[x], end=' ')