#Scrivi qui il tuo codice
N, K = tuple(map(int, input().strip().split()))


U = list(map(int, input().strip().split()))


i = 0
off = 0
while i < N - 1 - off:
    if off < K:
        if U[i] > U[i + 1]:
            U.pop(i)
            off += 1
            i = max(-1, i - 2)
    else:
        break
    i += 1


print(*U)
