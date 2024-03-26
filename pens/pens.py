#Scrivi qui il tuo codice
#Scrivi qui il tuo codice
N = int(input().strip())
P = [None] * N
P = list(map(int, input().strip().split()))
#print(P)
count = N
for i in range(N):
    if P[i] == 0:
        #print(P[min(i + 1, N - 1)], min(i + 1, N - 1))
        if P[max(i - 1, 0)] > 1:
            count -= 1
            P[max(i - 1, 0)] -= 1
        elif P[min(i + 1, N - 1)] > 1:
            count -= 1
            P[min(i + 1, N - 1)] -= 1
        #print(P)
    else:
        count -= 1
        #print(i)

print(count)