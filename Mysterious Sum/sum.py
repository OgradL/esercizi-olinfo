#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.


# input data
operand1 = input().strip()  # read as string
operand2 = input().strip()  # read as string
result   = input().strip()  # read as string, use int() if you want an integer
N = len(operand1)
assert(len(operand1) == len(operand2))


def find_combination(op1, op2, result, N, A):
    
    used = [False] * 10
    print(A)
    
    for i in range(N):
        if A.count(i) > 1:
            A[i] += 1
            find_combination(op1, op2, result, N, A)
            break
        if A[ord(op1[i:i+1]) - 65] + A[ord(op2[i:i+1]) - 65] != result[i:i+1]:
            if not used[ord(op1[i:i+1]) - 65]:
                A[ord(op1[i:i+1]) - 65] += 1
                find_combination(op1, op2, result, N, A)
            elif not used[ord(op2[i:i+1]) - 65]:
                A[ord(op2[i:i+1]) - 65] += 1
                find_combination(op1, op2, result, N, A)
            else:
                A[ord(op1[i:i+1]) - 65] += 1
                find_combination(op1, op2, result, N, A)
            break
        else:
            used[ord(op1[i:i+1]) - 65] = True
            used[ord(op2[i:i+1]) - 65] = True
            
    print(A)
    
    
    pass




op1 = operand1
op2 = operand2

#A = 

result = find_combination(op1, op2, result, N, [0] * 10)



print(result)  # op1
print(result)  # op2
