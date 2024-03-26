
N, M = list(map(int, input().strip().split()))

classifica = [0] * N

for i in range(N):
    classifica[i] = int(input())

for i in range(M):
    s = list(map(int, input().strip().split()))
    classifica[s[0] - 1], classifica[s[1] - 1] = classifica[s[1] - 1], classifica[s[0] - 1]
    
    

print(classifica[0])
