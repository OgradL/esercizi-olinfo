
N, K = list(map(int, input().strip().split()))


H = list(map(int, input().strip().split()))

H.sort()

#print(H)

for i in range(N - 1):
    H[i] = abs(H[i] - H[i + 1])
H[N - 1] = 0

#print(H)

#print()

result = 1000000

for i in range(N - K + 1):
    #temp = H[i:i+K-1]
    #print(temp)
    somma = sum(H[i:i+K-1])
    result = min(result, somma)


print(result)

