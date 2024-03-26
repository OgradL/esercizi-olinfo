
import sys
import os

currentPath = os.path.dirname(__file__)

sys.stdin = open(os.path.join(currentPath, "input2.txt"), "r")
#sys.stdout = open("output.txt", "w")




N, T = list(map(int, input().strip().split()))


C = list(map(int, input().strip().split()))

B = [0] * N

A = ""

for i in range(T):
    A = str(input().strip())
    action = A[:1]
    A = A[1:]
    A = list(map(int, A.split()))
    #print(A)
    #print(i)
    if action == 'P':
        
        B[A[1]] += A[0]
        if B[A[1]] > C[A[1]]:
            
            overflow = B[A[1]] - C[A[1]]
            B[A[1]] = C[A[1]]
            
            #print("overflow", overflow, B[A[1]])
            
            #print(B)
            for j in range(A[1] + 1, N):
                B[j] += overflow
                overflow = B[j] - C[j]
                B[j] = min(B[j], C[j])
                #print("overflow", overflow, B[i])
                if overflow <= 0:
                    break
            #print("uffa", i, B)
        #print("P", i, B)
    else:
        print(B[A[0]])
    




