#!/usr/bin/env python3

# input data
N, V = map(int, input().strip().split())
prices = list(map(int, input().strip().split()))
vouchers = list(map(int, input().strip().split()))

prices.sort()
vouchers.sort()
#print(prices, vouchers)
num = 0
count = 0
for x in range(V):
    #print(x)
    if prices[num] <= vouchers[x]:
        count += 1
        num += 1
        #print(count, num)
    

print(count)  # print the result