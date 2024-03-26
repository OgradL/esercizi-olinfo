#!/usr/bin/env python3
N, Q = map(int, input().strip().split())
V = list(map(int, input().strip().split()))

def max_numbers(numbers):
    if len(numbers) == 1:
        record = int(bool(numbers[0]))
        record_and = numbers[0]
        record_xor = numbers[0]
    else:
        record = 0
        record_and = 0
        record_xor = 0
        
        n = 0
        while n < len(numbers):
            mx_n, mx_and, mx_xor = max_numbers(numbers[:n:])

            mx_and = mx_and & numbers[n]
            mx_xor = mx_xor ^ numbers[n]

            if mx_and and mx_xor:
                mx_n += 1

            if  mx_n > record:
                record = mx_n
                record_and = mx_and
                record_xor = mx_xor

            n+=1

    return record, record_and, record_xor

print(max_numbers(V)[0])

i = 0
while i < Q:
    pos, val = map(int, input().strip().split())
    V[pos -1] = val
    print(max_numbers(V)[0])
    i+=1
