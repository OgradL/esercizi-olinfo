import math
R, C, K = map(int, input().strip().split())
print(math.ceil(R / K) * math.ceil(C / K))